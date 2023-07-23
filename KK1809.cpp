//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
const int B=31;
int n,k,dis[N],ans;
struct Trie
{
	int son[2],sz;
}t[N*B];
int nT=1;
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
inline void Insert(int val)
{
	int cur=1;
	for(int i=31;i>=0;i--)
	{
		bool b=val&(1<<i);
		if(!t[cur].son[b])t[cur].son[b]=++nT;
		cur=t[cur].son[b];
		t[cur].sz++;
	}
}
inline void Solve(int val)
{
	int cur=1;
	for(int i=31;i>=0;i--)
	{
		if(!cur)return ;
		bool bk=k&(1<<i);
		bool bv=val&(1<<i);
		if(bk)ans+=t[t[cur].son[bv]].sz,cur=t[cur].son[bv^1];
		else cur=t[cur].son[bv];
	}
}
signed main()
{
	freopen("xor2.in","r",stdin);
	freopen("xor2.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u++,v++;
		addEdge(u,v,w);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)Insert(dis[i]);
	for(int i=1;i<=n;i++)Solve(dis[i]);
	cout<<(ans-n)/2;
	return 0;
}

