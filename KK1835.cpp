#include <bits/stdc++.h>
#define N 30023200
using namespace std;
int read()
{
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -f; c = getchar(); }
    while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}
const int maxN = 200005;
int n, m, c[maxN];  //c[i]: ��ɫ���
struct EDGE{
    int adj, to;
    EDGE(int a = -1, int b = 0): adj(a), to(b) {}
}edge[maxN << 1];
int head[maxN], cnt;
void add_edge(int u, int v)
{
    edge[cnt] = EDGE(head[u], v);
    head[u] = cnt ++ ;
}

int siz[maxN], son[maxN];
void dfs(int u, int fa)
{
    siz[u] = 1;
    for(int i = head[u]; ~i; i = edge[i].adj)
    {
        int v = edge[i].to;
        if(v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v]) son[u] = v;
    }
}

int color[maxN], ans[maxN], tot, nowSon;
void cal(int u, int fa, int val)
{
    if(!color[c[u]]) ++ tot;
    color[c[u]] += val;
    for(int i = head[u]; ~i; i = edge[i].adj)
    {
        int v = edge[i].to;
        if(v == fa || v == nowSon) continue;
        cal(v, u, val);
    }
}
void dsu(int u, int fa, bool op)    //op==0: ��ߣ���Ҫ���
{
    for(int i = head[u]; ~i; i = edge[i].adj) //���������
    {
        int v = edge[i].to;
        if(v == fa || v == son[u]) continue;
        dsu(v, u, false);
    }
    if(son[u]) dsu(son[u], u, true), nowSon = son[u]; //ͳ���ض��ӵĹ���
    cal(u, fa, 1), nowSon = 0; // ����ͳ������ӵĹ��ף���¼�ض���nowSon�������ض��ӵĹ��ף�
    ans[u] = tot;   //�õ�u�����Ĵ�
    if(!op) { cal(u, fa, -1); tot = 0; } // ���������ӣ������������Ӱ�졣
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    memset(head, -1, sizeof(head));
    n = read();
    for(int i = 0; i < n - 1; ++ i )
    {
        int u, v; u = read(); v = read();
        add_edge(u, v); add_edge(v, u);
    }
    for(int i = 1; i <= n; ++i ) c[i] = read();
    dfs(1, 0);
    dsu(1, 0, true);
    m = read();
    for(int i = 0; i < m; ++ i )
    {
        int u = read();
        printf("%d ", ans[u]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
