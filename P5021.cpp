//TEmPTaTiON
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 50005;
struct Edge {int v, w;};
vector<Edge> G[MAXN];
int N, M, L, cnt;
int f[MAXN];
inline bool cmp(int a, int b) 
{
	return a > b;
}
inline void dfs(int u, int fa) 
{
    multiset<int> s;
    for (vector<Edge>::iterator it = G[u].begin(); it != G[u].end(); it++) {
        int v = it -> v, w = it -> w;
        if (v == fa) continue;
        dfs(v, u);
        if (f[v] + w >= L) cnt++;
        else s.insert(f[v] + w);
    }
    while (!s.empty()) {
        multiset<int>::iterator it = s.begin();
        s.erase(it);
        multiset<int>::iterator it1 = s.lower_bound(L - *it);
        if (it1 == s.end())
            f[u] = max(f[u], *it);
        else {
            cnt++;
            s.erase(it1);
        }
    }
}
inline bool check()
{
    memset(f, 0, sizeof(f));
    cnt = 0;
    dfs(1, 0);
    if (cnt >= M) return 1;
    return 0;
}
signed main()
{
    scanf("%lld%lld", &N, &M);
    for (register int i = 1; i < N; ++i) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back((Edge){v, w});
        G[v].push_back((Edge){u, w});
    }
    int l = 0, r = 5e8+5;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        L = mid;
        if (check()) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%lld", ans);
    return 0;
}
