//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline double calc(double x)
{
	return x*x*x+x*x+x-1;
}
signed main()
{
	double l=0,r=1;
	while(r-l>=0.01)
	{
		double mid=(l+r)/2;
		int ans=calc(mid);
		if(ans>=0)r=mid;
		else l=mid;
	}
	cout<<l<<' '<<r;
	return 0;
}

