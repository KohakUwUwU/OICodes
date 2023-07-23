//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=305;
int n,m,a[N],p[N],sz[N];
int f[N][N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs_sz(int u,int fa)
{
	sz[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_sz(v,u);
		sz[u]+=sz[v];
	}
}
inline int dfs_calc(int u,int step,int rem)
{
	int v=G[u][step];
	if(step==G[u].size()-1)
	{
		if(rem>sz[v])return -114514114514;
		return f[v][rem];
	}
	int ans=-114514114514;
	for(int i=0;i<=rem;i++)
	{
		ans=max(ans,f[v][i]+dfs_calc(u,step+1,rem-i));
	}
	return ans;
}
inline void dfs_dp(int u,int fa)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs_dp(v,u);
	}
	for(int i=1;i<=sz[u];i++)f[u][i]=dfs_calc(u,0,i);
}
signed main()
{
	cin>>n>>m;
	m++;
	for(int i=2;i<=n+1;i++)
	{
		int k,s;
		cin>>k>>s;
		k++;
		p[i]=k;
		addEdge(i,k);
		a[i]=s;
	}
	dfs_sz(1,0);
	dfs_dp(1,0);
	cout<<f[1][m];
	return 0;
}

