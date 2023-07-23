//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NR=5e4+10;
const int MR=1e5+10;
int n,m,d[65],to[MR<<1],nxt[MR<<1],val[MR<<1],head[NR],tot=1,vis[NR],dis[NR];
inline void add(int x,int y,int z)
{
	to[tot]=y;
	val[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot++;
}
inline void addnum(int x)
{
	for(int i=63;i>=0;i--)
	{
		if((x>>i)&1)
		{
			if(!d[i])
			{
				d[i]=x;
				break;
			}
			x^=d[i];
		}
	}
}
inline int search(int x)
{
	for(int i=63;i>=0;i--)
	{
		if((x^d[i])>x)
		{
			x^=d[i];
		}
	}
	return x;
}
inline void dfs(int x,int num)
{
	dis[x]=num;vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(!vis[y]) dfs(y,num^val[i]);
		else addnum(num^dis[y]^val[i]);
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	cout<<search(dis[n]);
	return 0;
}

