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

int t,m,p,n_fake=2e5+1,n,seg[(int)1e6];
inline int Query(int p,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return seg[p];
	if(l>y||r<x)return 0;
	int mid=l+r>>1;
	return max(Query(p*2,l,mid,x,y),Query(p*2+1,mid+1,r,x,y));
}
inline void Add(int p,int l,int r,int x,int num)
{
	if(l==r)
	{
		if(l!=x)return ;
		seg[p]=num;
		return ;
	}
	if(!(l<=x&&x<=r))return ;
	int mid=l+r>>1;
	Add(p*2,l,mid,x,num);
	Add(p*2+1,mid+1,r,x,num);
	seg[p]=max(seg[p*2],seg[p*2+1]);
}
signed main()
{
	cin>>m>>p;
	while(m--)
	{
		char opt;
		int x;
		cin>>opt>>x;
		if(opt=='Q')t=Query(1,1,n_fake,n-x+1,n),cout<<t<<'\n';
		else Add(1,1,n_fake,++n,(x+t)%p);
	}
	return 0;
}

