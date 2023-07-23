// Don't Fight The Music
#include <bits/stdc++.h>
#define int long long
using namespace std;

#define N 1001
#define pb push_back
#define mp make_pair
int n, m, u, v, w, match[N], h[N], tot, ans;
struct pi
{
    int fi,se;
    pi operator+(const pi&o)const{return {fi+o.fi,se+o.se};};
    pi operator-(const pi&o)const{return {fi-o.fi,se-o.se};};
    pi operator*(const pi&o)const{return {fi*o.fi,se*o.se};};
};

vector<pi> g[N];
queue<int> q;
void add(int u, int v, int w) { g[u].pb({v, w}); }
bool find(int x)
{
    for (auto i : g[x])
        if (!h[i.fi])
        {
            h[i.fi] = 1;
            if (!match[i.fi] || find(match[i.fi]))
            {
                match[i.fi] = x;
                ans += i.se;
                return 1;
            }
        }
    return 0;
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> u >> v >> w, add(u, v, w);
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (!q.empty())
    {
        memset(h, 0, sizeof h);
        if (find(q.front()))
            q.pop();
        else
            q.push(q.front()), q.pop();
    }
    cout << ans;
}

