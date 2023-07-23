//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=1e9+7;
inline int qpow(int k)
{
	int mul=2,ans=1;
	for(int i=0;i<=25;i++)
	{
		if(k&(1<<i))(ans*=mul)%=MOD;
		(mul*=mul)%=MOD;
	}
	return ans;
}
signed main()
{
	int a;
	cin>>a;
	cout<<qpow(a);
	return 0;
}

