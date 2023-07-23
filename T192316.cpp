//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,vis[N],clr[N],sz[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
    G[u].push_back(v),G[v].push_back(u);
}
inline int dfs(int u,bool clr)
{
    sz[u]=1;
    int ans=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(vis[v])continue;
        vis[v]=1;
        if(clr)ans++;
        dfs(v,!clr);
    }
    return ans;
}
signed main()
{
    int ans=0;
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++)cin>>u>>v,addEdge(u,v);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            int col=dfs(i,0);
            ans+=min(col,sz[i]-col);
        }
    }
    cout<<ans;
    return 0;
}