//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	for(int i=0;i<=23;i++)
	{
		for(int j=0;j<=59;j++)
		{
			cout<<i<<':';
			if(j<10)cout<<0;
			if(j%2==0)cout<<j<<" Ë¯¾õ\n";
			else cout<<j<<" Æð´²\n";
		}
	}
	return 0;
}

