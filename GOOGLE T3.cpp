//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int t,n,a[N];
signed main()
{
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		cout<<"Case #"<<tt<<": ";
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		int cur=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=cur)cur++;
		}
		cout<<cur-1<<'\n';
	}
	return 0;
}

