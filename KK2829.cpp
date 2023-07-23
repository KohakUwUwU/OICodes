//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
const unsigned int HA=114514191981;
struct Segment
{
	unsigned int fw,bw;
}t[N<<2];
int T,n,a[N];
unsigned int P[N];
#define mid (l+r>>1)
#define lc (p<<1)
#define rc (p<<1|1)
inline unsigned int Q1(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].fw;
	if(x>r||y<l)return 0;
	return Q1(l,mid,x,y,lc)*P[mid+1-l]+Q1(mid+1,r,x,y,rc);
}
inline unsigned int Q2(int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)return t[p].bw;
	if(x>r||y<l)return 0;
	return Q2(l,mid,x,y,lc)+Q2(mid+1,r,x,y,rc)*P[r-mid-1];
}
inline void Add(int l,int r,int pos,int p)
{
	if(l==r)
	{
		t[p]=(Segment){1,1};
		return ;
	}
	if(pos<=mid)Add(l,mid,pos,lc);
	else Add(mid+1,r,pos,rc);
	t[p].fw=t[lc].fw*P[mid+1-l]+t[rc].fw;
	t[p].bw=t[lc].bw+t[rc].bw*P[r-mid-1];
}
inline bool judge()
{
	memset(t,0,sizeof(t));
	Add(1,n,a[1],1);
	for(int i=2;i<n;i++)
	{
		Add(1,n,a[i],1);
		int maxLen=min(a[i]-1,n-a[i]);
		cout<<Q1(1,n,a[i]-maxLen,a[i],1)<<'\n'<<Q2(1,n,a[i],a[i]+maxLen,1)<<'\n';
		cout<<i<<'\n';
		if(Q1(1,n,a[i]-maxLen,a[i],1)!=Q2(1,n,a[i],a[i]+maxLen,1))
		{
			return true;
		}
	}
	return false;
}
signed main()
{
//	freopen("arithmetic.in","r",stdin);
//	freopen("arithmetic.out","w",stdout);
	cin>>T;
	P[0]=1;
	for(int i=1;i<=10001;i++)P[i]=P[i-1]*HA;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(judge())puts("Y");
		else puts("N");
	}
	return 0;
}

