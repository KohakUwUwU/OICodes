//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,rt,remain;
int d[N],vis[N],p[N];
vector<int>G[N];
vector<int>ans[N];int anscnt;
set<pair<int,int> >s;//第一关键字是dep 第二关键字的某个叶节点的id 
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void dfs(int u,int fa)
{
	p[u]=fa;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||vis[v])continue;
		dfs(v,u);
	}
	if(G[u].size()==1)if(d[u])s.erase(make_pair(d[u],u));
	d[u]=d[fa]+1;
	if(G[u].size()==1)s.insert(make_pair(d[u],u));
}
inline void up(int u)
{
	cout<<u<<'\n';
	anscnt++;
	while(u&&!vis[u])
	{
		remain--;
		vis[u]=1;
		ans[anscnt].push_back(u);
		d[u]=0;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(v==p[u]||vis[v])continue;
			dfs(v,u);
		}
		u=p[u];
		cout<<"%"<<remain<<'\n';
	}
}
inline void run()
{
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1;i<=anscnt;i++)ans[i].clear();
	anscnt=0;
	s.clear();
	cin>>n;
	remain=n;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		if(tmp==i)rt=i;
		else addEdge(i,tmp);
	}
	dfs(rt,0);
	while(remain)
	{
		set<pair<int,int> >::iterator iter;
		iter=s.begin();
		pair<int,int>pa=*iter;
		s.erase(pa);
		up(pa.second);
	}
	for(int i=1;i<=anscnt;i++)
	{
		cout<<ans[i].size()<<'\n';
		for(int j=ans[i].size()-1;j>=0;j--)cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
}
signed main()
{
	int T;
	cin>>T;
	while(T--)run();
	return 0;
}

