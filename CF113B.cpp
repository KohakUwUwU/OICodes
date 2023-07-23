//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int t,n,a[N];

signed main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=2;i<=(n/2)+1;i++)printf("%lld %lld\n",a[i],a[1]);
	}
	return 0;
}

