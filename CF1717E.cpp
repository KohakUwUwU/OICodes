//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int phi[N];
inline void prePhi()
{
	int n=1e5;
	for(int i=1;i<=n;i++)phi[i]=i;
	for(int i=2;i<=n;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<=n;j+=i)phi[j]=phi[j]/i*(i-1);
		}
	}
}
const int p=1e9+7;
signed main()
{
	int n;
	cin>>n;
	int ans=0;
	prePhi();
	for(int x=1; x*2<n; ++x)
	{
		int g=n/x,z=x/__gcd(n,x);
		for(int j=2; x*j<n; ++j)
			ans=(ans+z*(n-x*j)%p*phi[j])%p;
	}
	cout<<ans;
	return 0;
}

