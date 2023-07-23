//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
struct Segment
{
	int l,r,mx;
}t[N<<2];
int n,m,mmx,x[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,0};
	if(l==r)
	{
		t[p].mx=x[l];
		return ;
	}
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].mx=max(t[lc].mx,t[rc].mx);
}
inline void Turn(int l,int r,int pos,int s,int p)
{
	if(l==r)
	{
		t[p].mx=s;
	}
	if(pos<=mid)Turn(l,mid,pos,s,lc);
	else Turn(mid+1,r,pos,s,rc);
	t[p].mx=max(t[lc].mx,t[rc].mx);
}
inline int Query(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].mx;
	if(x>r||y<l)return 0;
	return max(Query(l,mid,x,y,lc),Query(mid+1,r,x,y,rc));
}
inline int Q(int pos)
{
	if(x[pos]==mmx)return 0;
	if(pos==n)return 0;
	int lo=21;
	while(lo>=0)
	{
		lo--;
		if(pos+(1<<lo)>n)continue;
		int temp=Query(1,n,pos,pos+(1<<lo),1);
		if(temp<x[pos])pos+=(1<<lo);
	}
	return pos+1;
}
signed main()
{
//	freopen("hero.in","r",stdin);
//	freopen("hero.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x[i],mmx=max(mmx,x[i]);
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		char opt;int pos,s;
		cin>>opt>>pos;
		if(opt=='M')
		{
			cin>>s;
			Turn(1,n,pos,s,1);
		}
		else
		{
			cout<<Q(i)<<'\n';
		}
	}
	return 0;
}

