//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1000007;
int n,a[N];
int lst[N],snd[N];
signed main()
{
	freopen("opt.in","r",stdin);
	freopen("opt.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int mx=*max_element(a+1,a+1+n);
	int T=log(mx)/log(2)+1;
	int nMsk=(1<<T);
	for(int k=1;k<=n;k++)
	{
		if(lst[a[k]])snd[a[k]]=lst[a[k]];
		lst[a[k]]=k;
	}
	for(int p=0;p<T;p++)
	{
		for(int msk=0;msk<nMsk;msk++)
		{
			if(((msk>>p)&1)==0)upd(msk,msk^(1<<p));
		}
	}
	int ans=0;
	for(int i=1;i<=n-2;i++)
	{
		int ones=0;
		for(int p=T-1;p>=0;p--)
		{
			if((a[i]>>p)&1)continue;
			if(snd[ones|(1<<p)]>i)ones|=(1<<p);
		}
		ans=max(ans,a[i]|ones);
	}
	cout<<ans;
	return 0;
}

