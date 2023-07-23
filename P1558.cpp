//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
struct Segment
{
	int state,tag;
}t[N<<2];
int n,c,m;
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline void build(int l,int r,int p)
{
	t[p].state=1<<1;
	if(l==r)return ;
	build(l,mid,lc);build(mid+1,r,rc);
}
inline void PushDown(int p)
{
	if(t[p].tag)
	{
		t[lc].tag=t[rc].tag=t[p].tag;
		t[lc].state=t[rc].state=(1<<t[p].tag);
	}
	t[p].tag=0;
}
inline void PushUp(int p)
{
	t[p].state=t[lc].state|t[rc].state;
}
inline void Paint(int l,int r,int x,int y,int z,int p)
{
//	cout<<l<<' '<<r<<'\n';
	PushDown(p);
	if(x<=l&&r<=y)
	{
		t[p].state=(1<<z);
		t[p].tag=z;
		return ;
	}
	if(x>r||y<l)return ;
	Paint(l,mid,x,y,z,lc);
	Paint(mid+1,r,x,y,z,rc);
	PushUp(p);
}
inline int lowbit(int x)
{
	return x&-x;
}
inline int calc(int x)
{
	int ans=0;
	while(x)x-=lowbit(x),ans++;
	return ans;
}
inline int Query(int l,int r,int x,int y,int p)
{
	PushDown(p);
	if(x<=l&&r<=y)return t[p].state;
	if(x>r||y<l)return 0;
	return Query(l,mid,x,y,lc)|Query(mid+1,r,x,y,rc);
}
signed main()
{
//	freopen("P1558_1.in","r",stdin);
//	freopen("P1558.out","w",stdout);
	cin>>n>>c>>m;
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		char opt;int x,y,z;
		cin>>opt>>x>>y;
		if(x>y)swap(x,y);
		if(opt=='C')cin>>z,Paint(1,n,x,y,z,1);
		else cout<<calc(Query(1,n,x,y,1))<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
