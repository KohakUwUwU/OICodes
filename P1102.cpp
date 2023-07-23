//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,c,a[N],ans;
unordered_map<int,int>v;
signed main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>a[i],v[a[i]]++;
	for(int i=1;i<=n;i++)ans+=v[a[i]+c];
	cout<<ans;
	return 0;
}

