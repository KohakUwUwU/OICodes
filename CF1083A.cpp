//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e5+5;
const int INF=114514114514;
int n,a[N],f[N][3];
vector<int>G[N],E[N];
inline void addEdge(int u,int v,int w)
{
	G[u].push_back(v),G[v].push_back(u);
	E[u].push_back(w),E[v].push_back(w);
}
inline void dfs(int u,int fa)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs(v,u);
		int val=max(f[v][1],a[v]);
		if(f[u][1]<val+E[u][i]+a[u]&&val+E[u][i]>=0)
		{
			f[u][2]=f[u][1];
			f[u][1]=val+E[u][i]+a[u];
		}
		else if(f[u][2]<val+E[u][i]+a[u]&&val+E[u][i]>=0)f[u][2]=val+E[u][i]+a[u];
	}
}
inline void print()
{
	for(int i=1;i<=n;i++)
	{
		cout<<i<<' '<<f[i][1]<<' '<<f[i][2]<<'\n';
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,-w);
	}
	for(int i=1;i<=n;i++)f[i][1]=0,f[i][2]=0;
//	print();
	dfs(1,0);
//	print();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i][2])ans=max(ans,f[i][1]+f[i][2]-a[i]);
		else ans=max(ans,f[i][1]);
		ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
}

