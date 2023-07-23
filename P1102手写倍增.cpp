//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,c,a[N];
inline int Search(int x)
{
	int pos=1;
	for(int i=30;i>=0;i--)
	{
		if(pos+(1<<i)>n)continue;
		if(a[pos+(1<<i)]<=x)pos+=(1<<i);
	}
	return pos;
}
signed main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)ans+=Search(a[i]+c)-Search(a[i]+c-1);
	cout<<ans;
	return 0;
}

