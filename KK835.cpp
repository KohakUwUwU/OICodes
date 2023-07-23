//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e4+5;
struct Segment
{
	int l,r,max,min;
}t[N<<2];
int n,m,a[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,a[l],a[l]};
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].max=max(t[lc].max,t[rc].max);
	t[p].min=min(t[lc].min,t[rc].min);
}
inline int Max(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].max;
	if(x>r||y<l)return -114514114514;
	return max(Max(l,mid,x,y,lc),Max(mid+1,r,x,y,rc));
}
inline int Min(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].min;
	if(x>r||y<l)return 114514114514;
	return min(Min(l,mid,x,y,lc),Min(mid+1,r,x,y,rc));
}
signed main()
{
	froepen("stock2.in","r",stdin);
	freopen("stock2.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<Max(1,n,l,r,1)-Min(1,n,l,r,1)<<'\n';
	}
	return 0;
}

