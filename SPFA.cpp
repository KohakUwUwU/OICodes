//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
const int INF=(1<<31)-1;
int n,m,s,in[N],d[N];
vector<int>G[N],E[N];
inline void addEdge(int u,int v,int w)
{
	G[u].push_back(v),E[u].push_back(w);
}
inline void SPFA()
{
	queue<int>q;
	q.push(s);
	in[s]=1;
	for(int i=1;i<=n;i++)d[i]=INF;
	d[s]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();in[u]=0;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(d[v]>d[u]+E[u][i])
			{
				d[v]=d[u]+E[u][i];
				if(!in[v])q.push(v),in[v]=1;
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
	SPFA();
	return 0;
}

