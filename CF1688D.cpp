//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF=114514114514;
const int N=2e5+5;
int a[N],loop[N];
signed main()
{
	for(int i=1;i<=2e5;i++)loop[i]=loop[i-1]+i*2;
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i],loop[i]=loop[i-1]+a[i];
		if(k<n)
		{
			int ans=-1;
			for(int i=k;i<=n;i++)ans=max(ans,loop[i]-loop[i-k]);
			cout<<ans+(k*k-k)/2<<'\n';
		}
		else
		{
			
			for(int i=1;i<=n;i++)a[i]+=k,loop[i]=a[i]+loop[i-1];
            cout<<loop[n]-(n*n+n)/2<<'\n';
		}
	}
	return 0;
}

