//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,p[N],ans[N];
map<int,int>ma[N];
inline void addEdge(int u,int v)
{
	p[u]=v;
}
inline void Add(int pos,int id)
{
	ma[pos][id]++;
	if(ma[pos][id]==1)ans[pos]++;
	if(pos==1)return ;
	Add(p[pos],id);
}
signed main()
{
//	freopen("adventure.in","r",stdin);
//	freopen("adventure.out","w",stdout);
	cin>>n>>m;
	for(int i=2,v;i<=n;i++)cin>>v,addEdge(i,v);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		Add(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<'\n';
	}
	return 0;
}

