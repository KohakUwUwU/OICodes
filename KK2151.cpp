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

const int N=1e6+7;
int n,m,c,cnt,a[N],s[N*4],b[N*4];
inline void build(int p,int x,int y)
{
	if(x==y)
	{
		s[p]=b[p]=a[x];
		return ;
	}
	int mid=x+y>>1;
	build(p*2,x,mid);build(p*2+1,mid+1,y);
	s[p]=min(s[p*2],s[p*2+1]);
	b[p]=max(b[p*2],b[p*2+1]);
} 
inline int BigQ(int p,int x,int y,int l,int r)
{
	if(l<=x&&y<=r)return b[p];
	if(x>r||y<l)return 0;
	int mid=x+y>>1;
	return max(BigQ(p*2,x,mid,l,r),BigQ(p*2+1,mid+1,y,l,r));
}
inline int SmallQ(int p,int x,int y,int l,int r)
{
	if(l<=x&&y<=r)return s[p];
	if(x>r||y<l)return 1e7;
	int mid=x+y>>1;
	return min(SmallQ(p*2,x,mid,l,r),SmallQ(p*2+1,mid+1,y,l,r));
}
signed main()
{
	n=read(),m=read(),c=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	for(int i=1;i+m-1<=n;i++)if(BigQ(1,1,n,i,i+m-1)-SmallQ(1,1,n,i,i+m-1)<=c)printf("%lld\n",i),cnt++;
	if(!cnt)cout<<"NONE";
	return 0;
}

