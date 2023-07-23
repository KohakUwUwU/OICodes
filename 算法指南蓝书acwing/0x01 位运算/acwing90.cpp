//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a,b,p;
signed main()
{
	int ans=0;
	cin>>a>>b>>p;
	for(;b;b>>=1)
	{
		if(b&1)(ans+=a)%=p;
		(a*=2)%=p;
	}
	cout<<ans;
	return 0;
}

