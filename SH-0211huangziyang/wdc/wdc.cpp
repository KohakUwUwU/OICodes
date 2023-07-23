//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=105;
int T,isAlice=0,sz[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs(int u,int fa)
{
	if(isAlice)return ;
	sz[u]=1;
	int ret=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[v]&1)ret++;
	}
	if(ret>=2)isAlice=1;
}
signed main()
{
	freopen("wdc.in","r",stdin);
	freopen("wdc.out","w",stdout);
	cin>>T;
	while(T--)
	{
		isAlice=0;
		int n,k;
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
		if(n&1)
		{
			cout<<"Alice"<<'\n';
			continue;
		}
		dfs(1,0);
		if(isAlice)cout<<"Alice"<<'\n';
		else cout<<"Bob"<<'\n';
	}
	return 0;
}
