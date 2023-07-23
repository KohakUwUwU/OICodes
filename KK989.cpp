//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=7e5+9;
int n,sum[N<<2];
inline void build(int l,int r,int p)
{
	sum[p]=r-l+1;
	int mid=l+r>>1;
	if(l==r)return;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
}
inline int upd(int l,int r,int k,int p)
{
	if(l==r)
	{
		--sum[p];
		return l;
	}
	int res=0,mid=l+r>>1;
	if(sum[p*2]>=k)res=upd(l,mid,k,p*2);
	else res=upd(mid+1,r,k-sum[p*2],p*2+1);
	sum[p]=sum[p*2]+sum[p*2+1];
	return res;
}
signed main()
{
	freopen("dealer.in","r",stdin);
	freopen("dealer.out","w",stdout);
	scanf("%lld",&n);
	build(1,n,1);
	int p=1;
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		p=(p+x)%(n-i+1);
		if(!p)p+=n-i+1; 
		printf("%d\n",upd(1,n,p,1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

