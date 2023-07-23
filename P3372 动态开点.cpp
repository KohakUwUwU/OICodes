//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,a[N];
struct Segment
{
	int l,r,len,ch[2],val,tag;
}t[N*2];
int cnt=1;
#define mid (l+r>>1)
inline int New(int p,int lr)
{
	int l=t[p].l,r=t[p].r;
	if(t[p].ch[lr])return t[p].ch[lr];
	else
	{
		t[p].ch[lr]=++cnt;
		if(!lr)t[cnt]=(Segment){l,mid,mid-l+1,{0,0},0,0};
		else t[cnt]=(Segment){mid+1,r,r-mid,{0,0},0,0};
		return cnt;
	}
}
#define lc (New(p,0))
#define rc (New(p,1))
inline void Insert(int l,int r,int pos,int val,int p)
{
	if(l==r)
	{
		t[p].val=val;
		return ;
	}
	if(pos<=mid)Insert(l,mid,pos,val,lc);
	else Insert(mid+1,r,pos,val,rc);
	t[p].val=t[lc].val+t[rc].val;
}
inline void PushDown(int p)
{
	if(!t[p].tag)return ;
	t[lc].tag+=t[p].tag;
    t[rc].tag+=t[p].tag;
	t[lc].val+=t[p].tag*t[lc].len;
	t[rc].val+=t[p].tag*t[rc].len;
	t[p].tag=0;
}
inline void Add(int l,int r,int x,int y,int val,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)
	{
		t[p].val+=val*t[p].len;
		t[p].tag=val;
		return ;
	}
	if(x>r||y<l)return ;
	Add(l,mid,x,y,val,lc);
	Add(mid+1,r,x,y,val,rc);
	t[p].val=t[lc].val+t[rc].val;
}
inline int Query(int l,int r,int x,int y,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)return t[p].val;
	if(x>r||y<l)return 0;
	return Query(l,mid,x,y,lc)+Query(mid+1,r,x,y,rc);
}
signed main()
{
	cin>>n>>m;
	t[1]=(Segment){1,n,n,{0,0},0,0};
	for(int i=1;i<=n;i++)cin>>a[i],Insert(1,n,i,a[i],1);
	for(int i=1;i<=m;i++)
	{
		int opt;
		cin>>opt;
		if(opt==1)
		{
			int l,r,k;
			cin>>l>>r>>k;
			Add(1,n,l,r,k,1);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			cout<<Query(1,n,l,r,1)<<'\n';
		}
	}
	return 0;
}

