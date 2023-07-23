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

const int N=2e5+5;
int n,m,a[N],seg[N*4];
inline void build(int p,int x,int y)
{
	if(x==y)
	{
		seg[p]=a[x];
		return ;
	}
	int mid=x+y>>1;
	build(p*2,x,mid);build(p*2+1,mid+1,y);
	seg[p]=max(seg[p*2],seg[p*2+1]);
}
inline int Query(int p,int x,int y,int l,int r)
{
	if(l<=x&&y<=r)return seg[p];
	if(x>r||y<l)return 0;
	int mid=x+y>>1;
	return max(Query(p*2,x,mid,l,r),Query(p*2+1,mid+1,y,l,r));
}
inline void Revise(int p,int x,int y,int pos,int res)
{
	if(!(x<=pos&&pos<=y))return ;
	if(x==y)
	{
		seg[p]=max(seg[p],res);
		return ;
	}
	int mid=x+y>>1;
	Revise(p*2,x,mid,pos,res);Revise(p*2+1,mid+1,y,pos,res);
	seg[p]=max(seg[p*2],seg[p*2+1]);
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		char opt;int x,y;
		cin>>opt>>x>>y;
		if(opt=='Q')cout<<Query(1,1,n,x,y)<<'\n';
		else Revise(1,1,n,x,y);
	}
	return 0;
}

