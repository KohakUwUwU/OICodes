#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
struct Segment
{
	int l,r,len,val,mul,add;
	//区间维护的信息:
	//区间端点以及长度，区间和，区间的乘法tag，区间的加法tag 
}t[N<<2];
int n,m,mod,a[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)//线段树的初始化 
{
	t[p]=(Segment){l,r,r-l+1,a[l]%mod,1,0};
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
	(t[p].val=t[lc].val+t[rc].val)%=mod;
}
inline void PushDown(int p)//线段树的tag下传 
{
	t[lc].val=(t[p].mul*t[lc].val+(t[lc].len*t[p].add)%mod)%mod;
	t[rc].val=(t[p].mul*t[rc].val+(t[rc].len*t[p].add)%mod)%mod;
	t[lc].mul=(t[lc].mul*t[p].mul)%mod;
	t[rc].mul=(t[rc].mul*t[p].mul)%mod;
	t[lc].add=(t[lc].add*t[p].mul+t[p].add)%mod;
	t[rc].add=(t[rc].add*t[p].mul+t[p].add)%mod;
	t[p].mul=1,t[p].add=0;
}
inline void Mul(int l,int r,int x,int y,int val,int p)//区间乘法 
{
	PushDown(p);
	if(x<=l&&r<=y)
	{
		(t[p].val*=val)%=mod,(t[p].mul*=val)%=mod;(t[p].add*=val);
		return ;
	}
	if(x>r||y<l)return ;
	Mul(l,mid,x,y,val,lc);Mul(mid+1,r,x,y,val,rc);
	(t[p].val=t[lc].val+t[rc].val)%=mod;
}
inline void Add(int l,int r,int x,int y,int val,int p)//区间加法 
{
	PushDown(p);
	if(x<=l&&r<=y)
	{
		(t[p].val+=val*t[p].len)%=mod;
		(t[p].add+=val)%=mod;
		return ;
	}
	if(x>r||y<l)return ;
	Add(l,mid,x,y,val,lc);Add(mid+1,r,x,y,val,rc);
	(t[p].val=t[lc].val+t[rc].val)%=mod;
}
inline int Query(int l,int r,int x,int y,int p)//询问区间和 
{
	PushDown(p);
	if(x<=l&&r<=y)return t[p].val%mod;
	if(x>r||y<l)return 0;
	return (Query(l,mid,x,y,lc)+Query(mid+1,r,x,y,rc))%mod;
}
signed main()
{
	cin>>n>>m>>mod;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]%=mod;
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y,k;
		cin>>opt;
		switch(opt)
		{
		case 1:
			cin>>x>>y>>k;
			Mul(1,n,x,y,k,1);
			break;
		case 2:
			cin>>x>>y>>k;
			Add(1,n,x,y,k,1);
			break;
		case 3:
			cin>>x>>y;
			cout<<Query(1,n,x,y,1)<<'\n';
			break;
		}
	}
	return 0;
}

