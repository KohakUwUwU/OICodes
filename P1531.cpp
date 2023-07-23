//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
struct Segment
{
	int l,r,val;
}t[N<<2];
int n,m,a[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,0};
	if(l==r)
	{
		t[p].val=a[l];
		return ;
	}
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].val=max(t[lc].val,t[rc].val);
}
inline int Query(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return -1;
	return max(Query(l,mid,x,y,lc),Query(mid+1,r,x,y,rc));
}
inline void Update(int l,int r,int x,int y,int p)
{
	if(l==r)
	{
		t[p].val=max(t[p].val,y);
		return ;
	}
	if(x<=mid)Update(l,mid,x,y,lc);
	else Update(mid+1,r,x,y,rc);
	t[p].val=max(t[lc].val,t[rc].val);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		char opt;int x,y;
		cin>>opt>>x>>y;
		if(opt=='Q')cout<<Query(1,n,x,y,1)<<'\n';
		else Update(1,n,x,y,1);
	}
	return 0;
}

