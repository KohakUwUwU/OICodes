//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

double a,s;
signed main()
{
	freopen("cooperation.in","r",stdin);
	freopen("cooperation.out","w",stdout);
	cin>>a>>s;
	cout<<ceil((-s+sqrt(s*s+4.0*a*s))/2.0/s);
	return 0;
}
