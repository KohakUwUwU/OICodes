//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
struct Num
{
	int val,id;
}a[N];
struct HJT
{
	int lc,rc,sum;
}hjt[N*50];
int n,m,cnt,ls,b[N],root[N],rps[N];//b 离散后原数组 rps 离散后每个数代表的原数 
inline bool cmp(Num x,Num y)
{
	return x.val<y.val;
}
inline void Insert(int l,int r,int pre,int&now,int p)
{
	now=++cnt;
	hjt[now]=hjt[pre];
	hjt[now].sum++;
	if(l==r)return ;
	int mid=l+r>>1;
	if(p<=mid)Insert(l,mid,hjt[pre].lc,hjt[now].lc,p);
	else Insert(mid+1,r,hjt[pre].rc,hjt[now].rc,p);
}
inline int query(int l,int r,int L,int R,int k)
{
	if(l==r)return l;
	int mid=l+r>>1;
	int tmp=hjt[hjt[R].lc].sum-hjt[hjt[L].lc].sum;
	if(tmp>=k)return query(l,mid,hjt[L].lc,hjt[R].lc,k);
	else return query(mid+1,r,hjt[L].rc,hjt[R].rc,k-tmp);	
}
signed main()
{
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i].val),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	int last=-114514;
	for(int i=1;i<=n;i++)
	{
		if(last!=a[i].val)ls++;
		b[a[i].id]=ls;
		rps[ls]=a[i].val;
		last=a[i].val;
	}
	for(int i=1;i<=n;i++)Insert(1,n,root[i-1],root[i],b[i]);
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		scanf("%lld %lld %lld",&l,&r,&k);
		printf("%lld\n",rps[query(1,n,root[l-1],root[r],k)]);
	}
	return 0;
}

