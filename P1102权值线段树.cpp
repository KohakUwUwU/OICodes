//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
struct Segment
{
	signed l,r,val,ch[2];
}t[3600000];int cnt;
int n,c,a[N];int ans;
inline int getNode(int lr,int p)
{
	if(t[p].ch[lr])return t[p].ch[lr];
	t[p].ch[lr]=++cnt;
	if(lr==0)
	{
		t[cnt]=(Segment){t[p].l,t[p].l+t[p].r>>1,0,{0,0}};
		return cnt;
	}
	else
	{
		t[cnt]=(Segment){(t[p].l+t[p].r>>1)+1,t[p].r,0,{0,0}};
		return cnt;
	}
}
#define mid (l+r>>1)
#define lc (getNode(0,p))
#define rc (getNode(1,p))
inline void Add(int l,int r,int val,int p)
{
	if(l==r)
	{
		t[p].val++;
		return ;
	}
	if(val<=mid)Add(l,mid,val,lc);
	else Add(mid+1,r,val,rc);
	t[p].val=t[lc].val+t[rc].val;
}
inline int Count(int l,int r,int val,int p)
{
	if(val>(1<<30)||val<-(1<<30))return 0;
	if(l==r)return t[p].val;
	if(val<=mid)return Count(l,mid,val,lc);
	else return Count(mid+1,r,val,rc);
}
signed main()
{
	freopen("P1102_3.in","r",stdin);
	cin>>n>>c;
	t[++cnt]=(Segment){-(1<<30),1<<30,0,{0,0}};
	for(int i=1;i<=n;i++)cin>>a[i],Add(-(1<<30),1<<30,a[i],1);
	for(int i=1;i<=n;i++)ans+=Count(-(1<<30),1<<30,a[i]+c,1);
	cout<<ans;
	return 0;
}

