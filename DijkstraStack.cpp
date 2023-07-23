#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,s,vis[N],d[N];
vector<int>G[N],E[N];
priority_queue<pair<int,int> >q;
inline void addEdge(int u,int v,int w)
{
	G[u].push_back(v);E[u].push_back(w);
}
inline void Dij()
{
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(d[v]>d[u]+E[u][i])
			{
				d[v]=d[u]+E[u][i];
				q.push(make_pair(-d[v],v));
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<d[i]<<' ';
}
signed main()
{
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	Dij();
	return 0;
}
