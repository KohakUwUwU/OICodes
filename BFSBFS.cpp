//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,m,vis[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	queue<int>q;
	q.push(1);vis[1]=1;
	while(!q.empty())
	{
		int u=q.front();
		cout<<u<<' ';
		q.pop();
		for(int  i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(vis[v])continue;
			vis[v]=1;
			q.push(v);
		}
	}
	return 0;
}

