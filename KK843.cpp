//LizPlum
#include<bits/stdc++.h>
using namespace std;

const int N=2500005;
const int INF=1e7;
struct Segment
{
	int l,r,len,ch[2],val,tag;
}t[N];
int cnt=1;
int m;
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
inline void PushDown(int p)
{
	if(!t[p].tag)return ;
	t[lc].tag+=t[p].tag;
	t[rc].tag+=t[p].tag;
	t[lc].val+=t[p].tag*t[lc].len;
	t[rc].val+=t[p].tag*t[rc].len;
	t[p].tag=0;
}
inline void Add(int l,int r,int x,int y,int k,int p)
{
	if(l!=r)PushDown(p);
	if(x<=l&&r<=y)
	{
		t[p].val+=k*t[p].len;
		t[p].tag=k;
		return ;
	}
	if(x>r||y<l)return ;
	Add(l,mid,x,y,k,lc);Add(mid+1,r,x,y,k,rc);
	t[p].val=t[lc].val+t[rc].val;
}
inline int Rank(int l,int r,int x,int p)
{
	if(l!=r)PushDown(p);
	if(l==r)return 1;
	if(x<=mid)return Rank(l,mid,x,lc);
	else return Rank(mid+1,r,x,rc)+t[lc].val;
}
inline int Kth(int l,int r,int k,int p)
{
	if(l!=r)PushDown(p);
	if(l==r)return l;
	int lsz=t[lc].val;
	if(lsz<k)return Kth(mid+1,r,k-lsz,rc);
	else if(lsz>=k)return Kth(l,mid,k,lc);
}
inline int Count(int x)
{
	int l=-INF,r=INF,p=1;
	while(l!=r)
	{
		PushDown(p);
		if(x<=mid)p=lc,r=mid;
		else p=rc,l=mid+1;
	}
	return t[p].val;
}
signed main()
{
	freopen("rank.in","r",stdin);
	freopen("rank.out","w",stdout);
	cin>>m;
	t[1]=(Segment){-INF,INF,2*INF+1,{0,0},0,0};
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		x=-x;
		Add(-INF,INF,x,x,1,1);
		cout<<Rank(-INF,INF,x,1)<<' ';
	}
//	for(int i=1;i<=m;i++)
//	{
//		int opt;
//		cin>>opt;
//		if(opt==1)
//		{
//			int x,y,k;
//			cin>>x>>y>>k;
//			Add(-INF,INF,x,y,k,1);
//		}
//		else if(opt==2)
//		{
//			int x;
//			cin>>x;
//			Add(-INF,INF,x,x,-1,1);
//		}
//		else if(opt==3)
//		{
//			int x;
//			cin>>x;
//			cout<<Rank(-INF,INF,x,1)<<'\n';
//		}
//		else if(opt==4)
//		{
//			int x;
//			cin>>x;
//			cout<<Kth(-INF,INF,x,1)<<'\n';
//		}
//		else if(opt==5)
//		{
//			int x;
//			cin>>x;
//			Add(-INF,INF,x,x,1,1);
//			cout<<Kth(-INF,INF,Rank(-INF,INF,x,1)-1,1)<<'\n';
//			Add(-INF,INF,x,x,-1,1);
//		}
//		else if(opt==6)
//		{
//			int x;
//			cin>>x;
//			Add(-INF,INF,x,x,1,1);
//			cout<<Kth(-INF,INF,Rank(-INF,INF,x,1)+Count(x),1)<<'\n';
//			Add(-INF,INF,x,x,-1,1);
//		}
//	}
	return 0;
}

