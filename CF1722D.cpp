//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int t,delta[N];
signed main()
{
	cin>>t;
	while(t--)
	{
		int n,cnt=0;
		cin>>n;
		fill(delta,delta+n+3,0);
		string str;
		cin>>str;
		for(int i=0;i<n/2;i++)
		{
			if(str[i]=='L')delta[++cnt]=n-2*i-1;
			if(str[str.length()-1-i]=='R')delta[++cnt]=n-2*i-1;
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='L')ans+=i;
			else ans+=n-i-1;
		}
		for(int i=1;i<=n;i++)
		{
			ans+=delta[i];
			cout<<ans<<' ';
		}
		cout<<'\n';
	}
	return 0;
}

