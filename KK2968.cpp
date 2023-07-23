//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e7+5;
int n,a[N],ans[N],f[N];
signed main()
{
	freopen("pair.in","r",stdin);
	freopen("pair.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int mx=*max_element(a+1,a+1+n);
	int T=log(mx)/log(2)+1;
	int nMsk=(1<<T);
	for(int i=1;i<=n;i++)f[a[i]]++;
	for(int p=1;p<=T;p++)
	{
		for(int msk=nMsk-1;msk>=0;--msk)
		{
			if((msk>>(p-1))&1)f[msk]+=f[msk^(1<<(p-1))];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int b=((1<<T)-1)^a[i];
		ans[i]=f[b];
	}
	int sum=0;
	for(int i=1;i<=n;i++)sum+=ans[i];
	cout<<sum;
	return 0;
}

