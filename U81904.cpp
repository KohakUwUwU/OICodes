//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
vector<int>G[N],E[N];
int f[N][3];
int ans=-1;
inline void addEdge(int u,int v,int w)
{
	G[u].push_back(v),G[v].push_back(u);
	E[u].push_back(w),E[v].push_back(w);
}
inline void dfs(int u,int fa)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i],e=E[u][i];
		if(v==fa)continue;
		dfs(v,u);
		if(f[u][1]<f[v][1]+e)f[u][2]=f[u][1],f[u][1]=f[v][1]+e;
		else
		{
			if(f[u][2]<f[v][1]+e)f[u][2]=f[v][1]+e;
		}
	}
//	cout<<u<<":"<<f[u][1]<<' '<<f[u][2]<<'\n';
	ans=max(ans,f[u][1]+f[u][2]);
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

