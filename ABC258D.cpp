//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,x,ans=9223372036854775807,a[N],b[N];
signed main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i],a[i]+=b[i];
	int sum=0;
	for(int i=1;i<=min(x,n);i++)
	{
		sum+=a[i];
		ans=min(ans,sum+(x-i)*b[i]);
	}
	cout<<ans;
	return 0;
}

