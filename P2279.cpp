//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+5;
int n,cnt,d[N],p[N],vis[N];
vector<int>G[N];
priority_queue<pair<int,int> >q;
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs(int u,int fa)
{
	d[u]=d[fa]+1,p[u]=fa;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs(v,u);
	}
	q.push(make_pair(d[u],u));
}
inline void Flood(int u,int fa,int dist)
{
	vis[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		if(dist<2)Flood(v,u,dist+1);
	}
}
signed main()
{
	cin>>n;
	for(int i=2,u;i<=n;i++)cin>>u,addEdge(u,i);
	dfs(1,0);
	while(!q.empty())
	{
		pair<int,int> pii=q.top();
		int u=pii.second;
		q.pop();
		if(vis[u])continue;
		cnt++;
		if(p[p[u]])Flood(p[p[u]],0,0);
		else if(p[u])Flood(p[u],0,0);
		else Flood(u,0,0);
	}
	cout<<cnt;
	return 0;
}