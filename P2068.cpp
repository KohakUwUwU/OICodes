//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+7;
struct Segment
{
	int l,r,val;
}t[N<<2];
int n,m;
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1) 
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,0};
	if(l==r)
	{
		return ;
	}
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].val=t[lc].val+t[rc].val;
}
inline void Add(int l,int r,int x,int val,int p)
{
	if(l==r)
	{
		t[p].val+=val;
		return ;
	}
	if(x<=mid)Add(l,mid,x,val,lc);
	else Add(mid+1,r,x,val,rc);
	t[p].val=t[lc].val+t[rc].val;
}
inline int Query(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return 0;
	return Query(l,mid,x,y,lc)+Query(mid+1,r,x,y,rc);
}
signed main()
{
	cin>>n>>m;
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		char opt;int x,y;
		cin>>opt>>x>>y;
		if(opt=='x')Add(1,n,x,y,1);
		else cout<<Query(1,n,x,y,1)<<'\n'; 
	}
	return 0;
}
