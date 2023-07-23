//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e3+5;
const int INF=114514114514;
int t,a[N];
signed main()
{
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int premin=INF,sucmax=-1;
		for(int i=1;i<n;i++)premin=min(premin,a[i]);
		for(int i=2;i<=n;i++)sucmax=max(sucmax,a[i]);
		int ans=max(a[n]-premin,sucmax-a[1]);
		ans=max(ans,a[n]-a[1]);
		for(int i=1;i<n;i++)ans=max(a[i]-a[i+1],ans);
		cout<<ans<<'\n';
	}
	return 0;
}

