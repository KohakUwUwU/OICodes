//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5,INF=1<<30;
struct Segment
{
	int l,r,min,max;
}t[N<<2];
int n,k,a[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,0,0};
	if(l==r)
	{
		t[p].min=t[p].max=a[l];
		return ;
	}
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].min=min(t[lc].min,t[rc].min);
	t[p].max=max(t[lc].max,t[rc].max);
}
inline int minQuery(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].min;
	if(x>r||y<l)return INF;
	return min(minQuery(l,mid,x,y,lc),minQuery(mid+1,r,x,y,rc));
}
inline int maxQuery(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].max;
	if(x>r||y<l)return -INF;
	return max(maxQuery(l,mid,x,y,lc),maxQuery(mid+1,r,x,y,rc));
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	for(int i=k;i<=n;i++)
	{
		cout<<minQuery(1,n,i-k+1,i,1)<<' ';
	}
	cout<<'\n';
	for(int i=k;i<=n;i++)
	{
		cout<<maxQuery(1,n,i-k+1,i,1)<<' ';
	}
	return 0;
}

