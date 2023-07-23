//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int n=2e5;
const int N=2e5+5;
const int INF=0x7fffffffffffffff;
struct Segment
{
	int l,r,val;
}t[N<<2];
int m,mod,cnt,T;
#define mid (l+r>>1) 
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,-INF};
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
}
inline void Add(int l,int r,int pos,int val,int p)
{
	if(l==r)
	{
		if(t[p].val==-INF)t[p].val=val;
		else t[p].val=((t[p].val+val)%mod+mod)%mod;
		return ;
	}
	if(pos<=mid)Add(l,mid,pos,val,lc);
	else Add(mid+1,r,pos,val,rc);
	t[p].val=max(t[lc].val,t[rc].val);
}
inline int Query(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return -INF;
	return max(Query(l,mid,x,y,lc),Query(mid+1,r,x,y,rc));
}
inline void print()
{
	for(int i=1;i<=10;i++)cout<<t[i].val<<' ';
	cout<<'\n';
}
signed main()
{
	cin>>m>>mod;
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		char c;int k;
		cin>>c>>k;
		if(c=='A')Add(1,n,++cnt,(k+T)%mod,1);
		else T=Query(1,n,cnt-k+1,cnt,1)%mod,cout<<T<<'\n';
//		print();
	}
	return 0;
}

