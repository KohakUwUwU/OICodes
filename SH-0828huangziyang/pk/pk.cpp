//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int T,n,k,s[N];
signed main()
{
	freopen("pk.in","r",stdin);
	freopen("pk.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>s[i];
		sort(s+1,s+1+n,greater<int>());
		int i=1;
		for(;i<n;i++)if(s[i]-s[i+1]>k)break;
		cout<<i<<'\n';
	}
	return 0;
}

