#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1e5, mod = 998244353;

int n, m, s[(maxn << 2) + 5], inv[maxn + 5]; 
int fenmu[maxn + 5]; 

struct BIT {
    int c[maxn + 5]; 
    int lb(int x) {
        return x & (-x); 
    }
    void add(int x, int d) {
        for (int i = x; i <= n; i += lb(i)) {
            c[i] += d; 
        }
    }
    int sum(int x) {
        int ret = 0; 
        for (int i = x; i; i -= lb(i)) {
            ret += c[i]; 
        }
        return ret; 
    } 
} B[2]; 

// 这个树状数组是为了维护我说的最后一种细节情况的。

int add(int x, int y) {
    return (x += y) >= mod ? x - mod : x; 
} 

int fpw(int x, int k, int p = mod) {
    int ret = 1; 
    while (k) {
        if (k & 1) ret = 1ll * ret * x % p; 
        x = 1ll * x * x % p; k >>= 1; 
    }
    return ret; 
}

struct Query {
    int l, r, op, id, len;  
} q[maxn + 5]; 

bool cmpl(Query x, Query y) {
    return x.l < y.l; 
}

bool cmpr(Query x, Query y) {
    return x.r < y.r; 
}

bool cmpid(Query x, Query y) {
    return x.id < y.id; 
}
 
struct matrix {
    int a[2][2]; 
    matrix() {
        memset(a, 0, sizeof(a)); 
    }
    matrix operator * (const matrix &x) const {
        matrix ret;
        ret.a[0][0] = add(1ll * a[0][0] * x.a[0][0] % mod, 1ll * a[0][1] * x.a[1][0] % mod); 
        ret.a[0][1] = add(1ll * a[0][0] * x.a[0][1] % mod, 1ll * a[0][1] * x.a[1][1] % mod); 
        ret.a[1][0] = add(1ll * a[1][0] * x.a[0][0] % mod, 1ll * a[1][1] * x.a[1][0] % mod); 
        ret.a[1][1] = add(1ll * a[1][0] * x.a[0][1] % mod, 1ll * a[1][1] * x.a[1][1] % mod); 
        return ret; 
    }
} dp[maxn + 5];

struct node {
    int s; matrix x; 
    node() {
        s = 1; 
        x.a[0][0] = x.a[1][1] = 1; 
        x.a[0][1] = x.a[1][0] = 0; 
    }
    node operator + (const node &t) const {
        node ret; 
        ret.s = 1ll * s * t.s % mod; 
        ret.x = x * t.x; 
        return ret;  
    }
} a[(maxn << 2) + 5]; 

void modify(int p, int l, int r, int pos, matrix x, int len, int op) {
    if (op == -1) {
        a[p].s = 1; 
        a[p].x.a[0][0] = a[p].x.a[1][1] = 1;
        a[p].x.a[0][1] = a[p].x.a[1][0] = 0;  
    }
    if (l == r) {
        if (op == -1) {
            return ; 
        }
        else {
            a[p].s = 1ll * a[p].s * len % mod; 
            a[p].x = a[p].x * x; 
        }
        return ; 
    }
    int mid = (l + r) >> 1; 
    if (pos <= mid) modify(p + p, l, mid, pos, x, len, op); 
    else modify(p + p + 1, mid + 1, r, pos, x, len, op); 
    if (op == 1) {
        a[p] = a[p + p] + a[p + p + 1]; 
    }
}

node query(int p, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) return a[p]; 
    int mid = (l + r) >> 1; 
    if (qr <= mid) return query(p + p, l, mid, ql, qr); 
    if (mid < ql)  return query(p + p + 1, mid + 1, r, ql, qr); 
    return query(p + p, l, mid, ql, mid) + query(p + p + 1, mid + 1, r, mid + 1, qr); 
}

void CDQ(int l, int r) {
    if (l >= r) return ; 
    int mid = (l + r) >> 1; 
    CDQ(l, mid); CDQ(mid + 1, r); 
    sort(q + l, q + mid + 1, cmpl); 
    sort(q + mid + 1, q + r + 1, cmpl); 
    // ([)] 边界严格
    int pos = l; 
    for (int i = mid + 1; i <= r; i++) {
        while (pos <= mid && q[pos].l <= q[i].l) {
            if (q[pos].op == 1) {
                matrix t; 
                t.a[0][0] = q[pos].len - 1, t.a[0][1] = 1; 
                t.a[1][0] = 1, t.a[1][1] = q[pos].len - 1; 
                modify(1, 0, n, q[pos].r, t, q[pos].len, 1); 
            }
            pos++; 
        }
        if (q[i].op == 2 && q[i].l != 0) {
            node t = query(1, 0, n, q[i].l, q[i].r - 1); 
            dp[q[i].id] = dp[q[i].id] * t.x; 
            if (q[i].id == 5) {
                
            }
            fenmu[q[i].id] = 1ll * fenmu[q[i].id] * t.s % mod; 
        }
    }
    for (int i = l; i < pos; i++) {
        if (q[i].op == 1) {
            modify(1, 0, n, q[i].r, dp[0], q[i].len, -1); 
        }
    }
    pos = l; 
    for (int i = mid + 1; i <= r; i++) {
        while (pos <= mid && q[pos].l <= q[i].l) {
            if (q[pos].op == 1) {
                matrix t; 
                t.a[0][0] = q[pos].len - 2, t.a[0][1] = 2; 
                t.a[1][0] = 2, t.a[1][1] = q[pos].len - 2; 
                modify(1, 0, n, q[pos].r, t, q[pos].len, 1); 
            }
            pos++; 
        }
        if (q[i].op == 2 && q[i].l) {
            node t = query(1, 0, n, q[i].r, n); 
            dp[q[i].id] = dp[q[i].id] * t.x; 

            fenmu[q[i].id] = 1ll * fenmu[q[i].id] * t.s % mod; 
        }
    }
    for (int i = l; i < pos; i++) {
        if (q[i].op == 1) {
            modify(1, 0, n, q[i].r, dp[0], q[i].len, -1); 
        }
    }
    // [(]) 边界严格
    sort(q + l, q + mid + 1, cmpr); 
    sort(q + mid + 1, q + r + 1, cmpr); 
    pos = mid; 
    for (int i = r; i >= mid + 1; i--) {
        while (pos >= l && q[pos].r >= q[i].r) {
            if (q[pos].op == 1) {
                matrix t; 
                t.a[0][0] = q[pos].len - 1, t.a[0][1] = 1; 
                t.a[1][0] = 1, t.a[1][1] = q[pos].len - 1; 
                modify(1, 0, n, q[pos].l, t, q[pos].len, 1);
            }
            pos--; 
        }
        if (q[i].op == 2 && q[i].l != 0) {
            node t = query(1, 0, n, q[i].l + 1, q[i].r); 
            dp[q[i].id] = dp[q[i].id] * t.x; 
            fenmu[q[i].id] = 1ll * fenmu[q[i].id] * t.s % mod; 
        }
    }
    for (int i = pos + 1; i <= mid; i++) {
        if (q[i].op == 1) {
            modify(1, 0, n, q[i].l, dp[0], q[i].len, -1); 
        }
    }
    pos = mid; 
    for (int i = r; i >= mid + 1; i--) {
        while (pos >= l && q[pos].r >= q[i].r) {
            if (q[pos].op == 1) {
                matrix t; 
                t.a[0][0] = 1, t.a[0][1] = q[pos].len - 1; 
                t.a[1][0] = q[pos].len - 1, t.a[1][1] = 1; 
                modify(1, 0, n, q[pos].l, t, q[pos].len, 1);
            }
            pos--; 
        }
        if (q[i].op == 2 && q[i].l == 0) {
            node t = query(1, 0, n, q[i].l + 1, q[i].r); 
            dp[q[i].id] = dp[q[i].id] * t.x; 
            fenmu[q[i].id] = 1ll * fenmu[q[i].id] * t.s % mod; 
        }
    }
    for (int i = pos + 1; i <= mid; i++) {
        if (q[i].op == 1) {
            modify(1, 0, n, q[i].l, dp[0], q[i].len, -1); 
        }
    }
}

int main() {
    scanf("%d %d", &n, &m); 
    inv[1] = 1; 
    for (int i = 2; i <= n + 1; i++) {
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &q[i].op, &q[i].l, &q[i].r);
        if (q[i].op == 2) {
            q[i].l = q[i].l - 1; 
        } 
        dp[i].a[0][0] = 1; dp[i].a[0][1] = 0; 
        fenmu[i] = 1; 
        q[i].id = i, q[i].len = q[i].r - q[i].l + 1; 
    }
    CDQ(1, m); 
    sort(q + 1, q + m + 1, cmpid); 
    for (int i = 1; i <= m; i++) {
        if (q[i].op == 2) {
            int fz = dp[i].a[0][0];
            int fm = fenmu[i], ans;
            if (q[i].l == 0) {
                int s1 = B[1].sum(q[i].r - 1); 
                int s2 = B[0].sum(n) - B[0].sum(q[i].r); 
                // cout << s1 << ' ' << s2 << '\n'; 
                if ((s1 + s2) & 1) {
                    fz = dp[i].a[0][1]; 
                }
            }
            ans = 1ll * fz * fpw(fm, mod - 2, mod) % mod; 
            printf("%d\n", ans); 
        }
        else {
            B[0].add(q[i].l, 1); 
            B[1].add(q[i].r, 1); 
        }
    }
    return 0; 
}
