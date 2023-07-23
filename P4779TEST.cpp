//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
const int INF=(1ll<<31)-1;
int n,m,s,vis[N],f[N];
vector<int>G[N],E[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
inline void addEdge(int u,int v,int w)
{
	G[u].push_back(v);E[u].push_back(w);
}
signed main()
{
	cin>>n>>m>>s;
	for(int i=1,u,v,w;i<=m;i++)cin>>u>>v>>w,addEdge(u,v,w);
	for(int i=1;i<=n;i++)f[i]=INF;
	f[s]=0;q.push(make_pair(0,s));
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(f[v]>f[u]+E[u][i])
			{
				f[v]=f[u]+E[u][i];
				q.push(make_pair(f[v],v));
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<f[i]<<' ';
	return 0;
}

