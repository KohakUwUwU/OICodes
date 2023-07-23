//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
struct Node
{
	int l,r,val;
}hjt[N*100];
int n,m,cnt,tot,rootfa[N],rootdep[N];
inline void build(int l,int r,int &p)
{
	p=++cnt;
	if(l==r)
	{
		hjt[p].val=++tot;
		return ;
	}
	int mid=l+r>>1;
	build(l,mid,hjt[p].l);
	build(mid+1,r,hjt[p].r);
}
inline void modify(int l,int r,int pre,int &now,int pos,int num)
{
	hjt[now=++cnt]=hjt[pre];
	if(l==r)
	{
		hjt[now].val=num;
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid)modify(l,mid,hjt[pre].l,hjt[now].l,pos,num);
	else modify(mid+1,r,hjt[pre].r,hjt[now].r,pos,num);
}
inline int query(int l,int r,int now,int pos)
{
	if(l==r)return hjt[now].val;
	int mid=l+r>>1;
	if(pos<=mid)return query(l,mid,hjt[now].l,pos);
	else return query(mid+1,r,hjt[now].r,pos);
}
inline int Find(int ver,int x)
{
	int fx=query(1,n,rootfa[ver],x);
	return fx==x?x:Find(ver,fx);
}
inline void Merge(int ver,int x,int y)
{
	x=Find(ver-1,x),y=Find(ver-1,y);
	if(x==y)
	{
		rootfa[ver]=rootfa[ver-1];
		rootdep[ver]=rootdep[ver-1];
	}
	else
	{
		int depx=query(1,n,rootdep[ver-1],x);
		int depy=query(1,n,rootdep[ver-1],y);
		if(depx<depy)
		{
			modify(1,n,rootfa[ver-1],rootfa[ver],x,y);
			rootdep[ver]=rootdep[ver-1];
		}
		else if(depx>depy)
		{
			modify(1,n,rootfa[ver-1],rootfa[ver],y,x);
			rootdep[ver]=rootdep[ver-1];
		}
		else 
		{
			modify(1,n,rootfa[ver-1],rootfa[ver],x,y);
			modify(1,n,rootdep[ver-1],rootdep[ver],y,depy+1);
		}
	}
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	build(1,n,rootfa[0]);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y;
		scanf("%lld",&opt);
		switch(opt)
		{
		case 1:
			scanf("%lld%lld",&x,&y);
			Merge(i,x,y);
			break;
		case 2:
			scanf("%lld",&x);
			rootfa[i]=rootfa[x];
			rootdep[i]=rootdep[x];
			break;
		case 3:
			scanf("%lld%lld",&x,&y);
			rootfa[i]=rootfa[i-1];
			rootdep[i]=rootdep[i-1];
			printf("%lld\n",(Find(i,x)==Find(i,y)?1:0));
			break;
		}
	}
	return 0;
}
