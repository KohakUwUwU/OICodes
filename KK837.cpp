//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
struct Segment
{
	int l,r,val;
}t[N<<2];
int m,n,aa[N],a[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,a[l]};
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].val=min(t[lc].val,t[rc].val);
} 
inline int Query(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return 114514114514;
	return min(Query(l,mid,x,y,lc),Query(mid+1,r,x,y,rc));
}
signed main()
{
	freopen("improvement.in","r",stdin);
	freopen("improvement.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>aa[i];
	for(int i=1;i<=n;i++)a[aa[i]]=i;
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<Query(1,n,l,r,1)<<' ';
	}
	return 0;
}

