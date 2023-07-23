//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*w;
}

const int N=1e5+5;
struct Segment
{
	int l,r,val,mul,plus;
	Segment()
	{
		mul=1;
	}
}t[N*4];
int n,m,p,a[N];
inline void build(int l,int r,int p)
{
	if(l==r)
	{
		t[p].l=l,t[p].r=r,t[p].val=a[l];
		return ;
	}
	int mid=l+r>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
inline void PushDown(int p)
{
//	t[p].val+=t[p].plus*(t[p].r-t[p].l+1);
	t[p*2].plus+=t[p].plus;t[p*2+1].plus+=t[p].plus;
	t[p*2].mul*=t[p].mul;t[p*2+1].mul*=t[p].mul;
	t[p*2].val*=t[p].mul;t[p*2+1].val*=t[p].mul;
	t[p].plus=0;t[p].mul=1;
}
inline void Add(int l,int r,int x,int y,int k,int p)
{
	if(l>y||r<x)return ;
	if(x<=l&&r<=y)
	{
		t[p].plus+=k;
		t[p].val+=k*(l-r+1);
		return ;
	}
	int mid=l+r>>1;
	PushDown(p);
	Add(l,mid,x,y,k,p*2);Add(mid+1,r,x,y,k,p*2+1);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
inline void Mul(int l,int r,int x,int y,int k,int p)
{
	if(l>y||r<x)return ;
	if(x<=l&&r<=y)
	{
		t[p].mul*=k;
		t[p].plus*=k;
		t[p].val*=k;
		return ;
	}
	int mid=l+r>>1;
	PushDown(p);
	Mul(l,mid,x,y,k,p*2);Mul(mid+1,r,x,y,k,p*2+1);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
inline int Sum(int l,int r,int x,int y,int p)
{
	PushDown(p);
	if(l>y||r<x)return 0;
	if(x<=l&&r<=y)
	{
		return t[p].val;
	}
	int mid=l+r>>1;
	return Sum(l,mid,x,y,p*2)+Sum(mid+1,r,x,y,p*2+1);
}
signed main()
{
	n=read(),m=read(),p=read();
	for(int i=1;i<=n;++i)a[i]=read();
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int opt=read(),x=read(),y=read(),k;
		if(opt==1)k=read(),Mul(1,n,x,y,k,1);
		if(opt==2)k=read(),Add(1,n,x,y,k,1);
		if(opt==3)cout<<Sum(1,n,x,y,1)<<'\n';
	}
	return 0;
}

