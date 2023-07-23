//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
#define db long double
using namespace std;

const int N=5e4+5;
struct Island
{
	db x,y;int q;
	Island()
	{
		x=y=q=0;
	}
}a[N];
int n,c,sumq[N];
db sum[N],f[N];
inline db dis(int i,int j)
{
	return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}
inline bool check(int i,int j)
{
	if(sumq[j]-sumq[i-1]>c)return false;
	return true;
}
db t[N<<2];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p]=114514114;
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
}
inline db Query(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p];
	if(x>r||y<l)return 114514114;
	return min(Query(l,mid,x,y,lc),Query(mid+1,r,x,y,rc));
} 
inline void Add(int l,int r,int pos,db val,int p)
{
	if(l==r)
	{
		t[p]=val;
		return ;
	}
	if(pos<=mid)Add(l,mid,pos,val,lc);
	else Add(mid+1,r,pos,val,rc);
	t[p]=min(t[lc],t[rc]);
}
signed main()
{
	freopen("seaway.in","r",stdin);
	freopen("seaway.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].q;
	for(int i=1;i<=n;i++)sumq[i]=sumq[i-1]+a[i].q;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+dis(i,i-1);
	build(1,n,1);
	f[1]=2.0*dis(0,1);Add(1,n,1,f[1]+dis(0,2)-sum[2],1);
	for(int i=2;i<=n;i++)
	{
		int j=i-1,lo=21;
		while(lo>0)
		{
			lo--;
			if(j-(1<<lo)<1)continue;
			if(check(j-(1<<lo)+1,i))j-=(1<<lo);
		}
		f[i]=sum[i]+dis(0,i)+Query(1,n,j,i-1,1);
		Add(1,n,i,f[i]+dis(0,i+1)-sum[i+1],1);
	}
	cout<<fixed<<setprecision(2)<<f[n];
	return 0;
}

