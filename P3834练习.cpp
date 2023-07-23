//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+5;
struct HJT
{
	int l,r,val;
}hjt[N*40];
struct NUM
{
	int val,id;
}a[N];
int n,m,b[N],rps[N],root[N],cnt;
inline bool cmp(NUM x,NUM y)
{
	return x.val<y.val;
}
inline void Insert(int l,int r,int pre,int &now,int p)
{
	hjt[now=++cnt]=hjt[pre];
	hjt[now].val++;
	if(l==r)return ;
	int mid=l+r>>1;
	if(p<=mid)Insert(l,mid,hjt[pre].l,hjt[now].l,p);
	else Insert(mid+1,r,hjt[pre].r,hjt[now].r,p);
}
inline int query(int l,int r,int pre,int now,int k)
{
	if(l==r)return l;
	int sum=hjt[hjt[now].l].val-hjt[hjt[pre].l].val;
	int mid=l+r>>1;
	if(sum>=k)return query(l,mid,hjt[pre].l,hjt[now].l,k);
	else return query(mid+1,r,hjt[pre].r,hjt[now].r,k-sum);
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i].val),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	int lastnum=-114514,nC=0;
	for(int i=1;i<=n;i++)
	{
		if(lastnum!=a[i].val)nC++;
		b[a[i].id]=nC;rps[nC]=a[i].val;
		lastnum=a[i].val;
	}
	for(int i=1;i<=n;i++)Insert(1,n,root[i-1],root[i],b[i]);
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		scanf("%lld%lld%lld",&l,&r,&k);
		printf("%lld\n",rps[query(1,n,root[l-1],root[r],k)]);
	}
	return 0;
}

