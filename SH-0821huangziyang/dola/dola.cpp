//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
int n,a[N],b[N];
signed main()
{
	freopen("dola.in","r",stdin);
	freopen("dola.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(a+1,a+1+n,greater<int>());sort(b+1,b+1+n,greater<int>());
	for(int i=1;i<=n;i++)cout<<a[i]<<' '<<b[i]<<' ';
	return 0;
}

