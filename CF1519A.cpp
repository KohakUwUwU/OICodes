//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,b,d;
		cin>>r>>b>>d;
		if(r<b)swap(r,b);
		if(double(r-b)/(double)b<=d)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

