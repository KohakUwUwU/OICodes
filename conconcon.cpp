//TEmPTaTiON
#include<iostream>
#define int long long
using namespace std;

int n,m,s;
vector<int>G[N],E[N];
inline void addEdge(int u,int v,int w)
{
    G[u].push_back(v),G[v].push_back(u);
    E[u].push_back(w),E[v].push_back(w);
}
inline void dijstra()
{
    
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    dijstra();
    return 0;
}