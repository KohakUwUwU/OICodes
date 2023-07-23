//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
const int B=31;
struct Trie
{
	int son[2];
}t[N*B];
int nT=1;
int n,dis[N];
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
		dis[v]=dis[u]^E[u][i];
		dfs(v,u);
	}
}
inline void Insert(int k)
{
	int cur=1;
	for(int i=31;i>=0;i--)
	{
		bool b=k&(1<<i);
		if(!t[cur].son[b])t[cur].son[b]=++nT;
		cur=t[cur].son[b];
	}
}
inline int Query(int k)
{
	int ans=0,cur=1;
	for(int i=31;i>=0;i--)
	{
		bool b=k&(1<<i);
		if(t[cur].son[!b])ans+=(1<<i),cur=t[cur].son[!b];
		else cur=t[cur].son[b];
	}
	return ans;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)Insert(dis[i]);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,Query(dis[i]));
	cout<<ans;
	return 0;
}

