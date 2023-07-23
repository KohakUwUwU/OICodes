//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

int s,k;
inline int sum(int l,int r)
{
	return r*s+r*k*(r-1)/2-(l-1)*s-(l-1)*k*((l-1)-1)/2;
}
signed main()
{
	int m;
	cin>>s>>k>>m;
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		cout<<sum(l,r)<<'\n';
	}
	return 0;
}

