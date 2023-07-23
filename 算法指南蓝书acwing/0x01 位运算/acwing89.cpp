//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int power(int a,int b,int p)
{
	int ans=1%p;
	for(;b;b>>=1)
	{
		if(b&1)(ans*=a)%=p;
		(a*=a)%=p;
	}
	return ans;
}
signed main()
{
	int a,b,p;
	cin>>a>>b>>p;
	cout<<power(a,b,p);
	return 0;
}
