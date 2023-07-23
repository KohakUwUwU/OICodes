//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=105;
int n,a[N];
inline void work()
{
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])
		{
			cout<<"NO\n";
			return ;
		}
		a[i]=a[i]%a[i-1]+a[i-1];
	}
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//	cout<<'\n';
	for(int i=2;i<=n;i++)if(a[i]%a[1]!=0)
	{
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		work();
	}
	return 0;
}

