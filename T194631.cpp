//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+5;
int n,m,ans[N][N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline bool check(int i,int j)//G[j]是否有[i,j)中的连边
{
	int ans=lower_bound(G[j].begin(),G[j].end(),j)-lower_bound(G[j].begin(),G[j].end(),i);
	if(ans)return true;
	return false;
} 
signed main()
{
	cin>>n>>m;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,addEdge(u,v);
	for(int i=1;i<=n;i++)sort(G[i].begin(),G[i].end());
	for(int i=1;i<=n;i++)
	{
		int sz=1;ans[i][i]=1;
		for(int j=i+1;j<=n;j++)
		{
			if(!check(i,j))sz++;
			ans[i][j]=sz;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]<<'\n';
	}
	return 0;
}

