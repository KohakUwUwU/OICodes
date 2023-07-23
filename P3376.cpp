//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=205;
const int M=5e3+5;
const int INF=114514114514;
int n,m,s,t;
int hd[N],to[2*M],nxt[2*M],e[2*M],cnt=1;
int lv[N],cur[N];//lv为层数 cur为当前弧
int ans;
inline void addEdge(int u,int v,int w)
{
	to[++cnt]=v,nxt[cnt]=hd[u],hd[u]=cnt,e[cnt]=w;
}
inline bool bfs()
{
	memset(lv,0,sizeof(lv));
	queue<int>q;
	q.push(s);
	lv[s]=1;
	cur[s]=hd[s];
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=hd[u];i;i=nxt[i])
		{
			int v=to[i];
			if(e[i]&&!lv[v])
			{
				q.push(v);
				cur[v]=hd[v];
				lv[v]=lv[u]+1;
				if(v==t)return 1;
			}
		}
	}
	return 0;
}
inline int dfs(int u,int f)
{
	if(u==t)return f;
	int res=0;
	for(int i=cur[u];i&&f;i=nxt[i])
	{
		cur[u]=i;
		int v=to[i];
		if(e[i]&&lv[v]>lv[u])
		{
			int k=dfs(v,min(f,e[i]));
			if(!k)lv[v]=0;
			e[i]-=k;e[i^1]+=k;
			res+=k;f-=k;
		}
	}
	return res;
}
signed main()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
		addEdge(v,u,0);
	}
	while(bfs())ans+=dfs(s,INF);
	cout<<ans<<'\n';
	return 0;
}