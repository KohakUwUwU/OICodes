//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5;
struct Segment
{
	int l,r,val0,val1,rev;
}t[N<<2];
int n,m,a[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p]=(Segment){l,r,0,0,0};
	if(l==r)
	{
		int u=a[l];
		if(u==0)t[p].val0++;
		else t[p].val1++;
		return ;
	}
	build(l,mid,lc);build(mid+1,r,rc);
	t[p].val0=t[lc].val0+t[rc].val0;
	t[p].val1=t[lc].val1+t[rc].val1;
}
inline void PushDown(int p)
{
	t[lc].rev^=t[p].rev;
	t[rc].rev^=t[p].rev;
	if(t[p].rev)swap(t[lc].val0,t[lc].val1);
	if(t[p].rev)swap(t[rc].val0,t[rc].val1);
	t[p].rev=0;
}
inline void Reverse(int l,int r,int x,int y,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)
	{
		swap(t[p].val0,t[p].val1);
		t[p].rev=1;
		return ;
	}
	if(x>r||y<l)return ;
	Reverse(l,mid,x,y,lc);
	Reverse(mid+1,r,x,y,rc);
	t[p].val0=t[lc].val0+t[rc].val0;
	t[p].val1=t[lc].val1+t[rc].val1;
}
inline int Query(int l,int r,int x,int y,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)return t[p].val1;
	if(x>r||y<l)return 0;
	return Query(l,mid,x,y,lc)+Query(mid+1,r,x,y,rc);
}
signed main()
{
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++)a[i+1]=str[i]-'0';
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==0)Reverse(1,n,x,y,1);
		else cout<<Query(1,n,x,y,1)<<'\n';
	}
	return 0;
}

