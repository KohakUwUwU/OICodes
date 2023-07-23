//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int a[N],b[N];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		for(int i=1;i<n;i++)
		{
			if(a[i]==b[i])continue;
			if(a[i]>b[i]||b[i+1]<b[i]-1)
			{
				cout<<"NO\n";
				goto sbga;
			}
		}
		if(a[n]==b[n])
		{
			cout<<"YES\n";
			goto sbga;
		}
		if(a[n]>b[n]||b[1]<b[n]-1)
		{
			cout<<"NO\n";
			goto sbga;
		}
		cout<<"YES\n";
		sbga:;
	}
	return 0;
}

