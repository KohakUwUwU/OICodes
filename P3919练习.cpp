//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e6+5;
struct HJT
{
	int l,r,val;
}hjt[N*40];
int n,m,cnt,a[N],root[N];
inline void build(int l,int r,int &p)
{
	p=++cnt;
	if(l==r)
	{
		hjt[p].val=a[l];
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
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,n,root[0]);
	for(int i=1;i<=m;i++)
	{
		int ver,opt,loc,val;
		scanf("%lld%lld",&ver,&opt);
		switch(opt)
		{
		case 1:
			scanf("%lld%lld",&loc,&val);
			modify(1,n,root[ver],root[i],loc,val);
			break;
		case 2:
			scanf("%lld",&loc);
			printf("%lld\n",query(1,n,root[ver],loc));
			root[i]=root[ver];
			break;
		}
	}
	return 0;
}

