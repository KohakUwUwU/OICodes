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

const int N=1e5+5,mod=1e8+7;
struct Segment
{
	int l,r,len,val,tag;
}t[N<<4];
int n,m,opt,x,y,z; 
inline void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r,t[p].len=r-l+1;
	if(l==r)return ;
	int mid=l+r>>1;
	build(l,mid,p*2);build(mid+1,r,p*2+1);
}
inline void PushDown(int p)
{
	(t[p*2].tag+=t[p].tag)%=mod;(t[p*2+1].tag+=t[p].tag)%=mod;
	(t[p*2].val+=t[p].tag*t[p*2].len)%=mod;
	(t[p*2+1].val+=t[p].tag*t[p*2+1].len)%mod;
	t[p].tag=0;
}
inline void Add(int l,int r,int x,int y,int z,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)
	{
		(t[p].tag+=z)%=mod;
		(t[p].val+=z*t[p].len)%=mod;
		return ;
	}
	if(x>r||y<l)return ;
	int mid=l+r>>1;
	Add(l,mid,x,y,z,p*2);Add(mid+1,r,x,y,z,p*2+1);
}
inline int Sum(int l,int r,int x,int y,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return 0;
	int mid=l+r>>1;
	return (Sum(l,mid,x,y,p*2)+Sum(mid+1,r,x,y,p*2+1))%mod;
}
signed main()
{
	n=read(),m=read();
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		opt=read(),x=read(),y=read(),z=read();
		if(opt==1)Add(1,n,x,y,z,1);
		else cout<<Sum(1,n,x,y,1)<<'\n';
	}
	return 0;
}

