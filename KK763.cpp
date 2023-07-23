#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,T;
int x,y,z;
int nxt[N*2],first[N*2],go[N*2],tot,dep[N],f[N][100];
inline int add(int u,int v)
{
	nxt[++tot]=first[u],first[u]=tot,go[tot]=v;
	nxt[++tot]=first[v],first[v]=tot,go[tot]=u;
}
inline void deal_first(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(int i=0;i<20;i++)f[u][i+1]=f[f[u][i]][i];
	for(int e=first[u];e;e=nxt[e])
	{
		int v=go[e];
		if(v==fa)continue;
		f[v][0]=u;
		deal_first(v,u);
	}
}
inline int lca(int xx,int yy)
{
	if(dep[xx]<dep[yy])swap(xx,yy);
	for(int i=20;i>=0;i--)
	{
		if(dep[f[xx][i]]>=dep[yy])xx=f[xx][i];
		if(xx==yy)return xx;
	}
	for(int i=20;i>=0;i--)
	{
		if(f[xx][i]!=f[yy][i])
		{
			xx=f[xx][i];
			yy=f[yy][i];
		}
	}
	return f[xx][0];
}
int dist(int xx,int yy)
{
	return dep[xx]+dep[yy]-2*dep[lca(xx,yy)];
}
int main()
{
	cin>>n>>T;
	for(int i=1;i<n;i++)cin>>x>>y,add(x,y);
	deal_first(1,0);
	while(T--)cin>>x>>y>>z,cout<<dist(x,y)<<endl;
	return 0;
}
