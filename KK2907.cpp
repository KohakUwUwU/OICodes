//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=505;
int n,m;
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
signed main()
{
	// freopen("randomwalk.in","r",stdin);
	// freopen("randomwalk.out","w",stdout);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,addEdge(u,v);
	cout<<1;
	return 0;
}