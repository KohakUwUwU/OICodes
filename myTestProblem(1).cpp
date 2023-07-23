#include <iostream>

typedef unsigned long long ull;
#define int ull
const int MAX = 100005;
const ull p = 998244353;

void write(int x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}


int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ch = getchar();
  }
  return x * w;
}

ull inv(const ull& n) {
    ull a = 1, b = n % p, c = p - 2;
    while(c){
        if(c & 1) a = a * b % p;
        b = b * b % p;
        c >>= 1;
    }
    return a;
}

int lowbit(const int& n)
    {return n & -n;}

struct TanVal {
    ull val;
    TanVal(const ull _val) : val(_val){
        val = (val % p);
        if(val < 0) val += p;
    }

    TanVal() : val(0){}

    TanVal operator-() const 
        {return TanVal(p - val);}
    
    TanVal operator+(const TanVal &o) const 
        {return TanVal(((val + o.val) % p) * inv(p + 1 - (val * o.val) % p));}

    TanVal operator-(const TanVal& o) const
        {return *this + (-o);}
};

struct TanTree {
    TanVal T[MAX];
    int _size;

    void build(ull *l, int size) {
        _size = size;
        TanVal last, prst(0);
        int j;
        for(int i = 1; i <= size; i++) {
            last = prst;
            prst = TanVal(l[i]);
            T[i] = T[i] + (prst - last);
            j = i + lowbit(i);
            if(j <= size)
                T[j] = T[j] + T[i];
        }
    }

    void _add(const int& pos, const TanVal& val) {
        for(int a = pos; a <= _size; a += lowbit(a))
            T[a] = T[a] + val;
    }

    void rotate(const int& start, const int& end, const TanVal& val) {
        _add(start, val);
        if(end < _size)
            _add(end + 1, -val);
    }

    TanVal cauculate(const int& i) {
        TanVal ret(0);
        for(int a = i; a; a -= lowbit(a))
            ret = ret + T[a];
        return ret;
    }
}tree;

ull tans[MAX], tmpc;
int n, t, op, tmpa, tmpb;
TanVal tmpres;
signed main(){
	freopen("data1.in","r",stdin);
//	freopen("tan.ans","w",stdout);
	n = read(); t = read();
    for(int i = 1; i <= n; i++)
        tans[i] = read();
    tree.build(tans, n);
    while(t--){
        op = read();
        switch(op) {
        case 1:
            tmpa = read(); tmpb = read(); tmpc = read();
            tree.rotate(tmpa, tmpb, TanVal(tmpc));
            break;
        case 2:
            tmpa = read(); tmpb = read();
            tmpres = tree.cauculate(tmpb) - tree.cauculate(tmpa);
            printf("%llu\n",tmpres.val);
        default:
            break;
        }
    }
    return 0;
}
