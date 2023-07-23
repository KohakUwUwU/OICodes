//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,c,a[N];
map<int,int>ma;
signed main()
{
	int ans=0;
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>a[i],ma[a[i]]++;
	for(int i=1;i<=n;i++)ans+=ma[a[i]+c];
	cout<<ans;
	return 0;
}

