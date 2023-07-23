//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e7+5;
int n,a[N],p[N],b[N],colorcnt[N],val,ans;
vector<int>G[N],l;
unordered_map<int,int>m;
inline void addEdge(int u,int v)
{
	G[u].push_back(v),G[v].push_back(u);
}
inline void calc(int u,int fa)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		calc(v,u);
	}
	if(G[u].size())b[u]=b[G[u][1]]^1;
	if(b[u])++m[a[u]];
	else
	{
		val^=a[u];
		l.push_back(a[u]);
	}
	colorcnt[b[u]]++;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)cin>>p[i],addEdge(p[i],i);
	calc(1,0);
	if(val)
	{
		for(int i=0;i<l.size();i++)if(l[i]^val<=1e7)ans+=m[l[i]^val];
	}
	else
	{
		ans=(colorcnt[0]*(colorcnt[0]-1)+colorcnt[1]*(colorcnt[1]-1))/2;
		for(int i=0;i<l.size();i++)ans+=m[l[i]^val];
	}
	cout<<ans;
	return 0;
}

