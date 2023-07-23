//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[35];
signed main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,cnt=0,t=1;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=n-1;i>=1;i--)
		{
			while(a[i]>a[i+1])a[i]/=2,cnt++;
			if(a[i]==a[i+1]&&a[i]==0)
			{
				t=0;
				break;
			}
			else if(a[i]==a[i+1])a[i]/=2,cnt++;
		}
		if(t)cout<<cnt<<'\n';
		else cout<<"-1\n";
	}
	return 0;
}

