//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int ans=0;
	for(int n=1;n<=2012;n++)
	{
		if((n*n-n+3)*(n*n+n+3)%5==0)ans++;
	}
	cout<<ans;
	return 0;
}

