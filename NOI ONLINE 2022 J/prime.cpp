//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int check(int k)
{
	for(int i=2;i*i<=k;i++)if(k%i==0)return 0;
	return 1;
}
signed main()
{
	freopen("prime.out","w",stdout);
	int n=1e6;
	cout<<"2,3,";
	int cnt=0;
	for(int i=4;i<=n;i++)
	{
		if(check(i))cout<<i<<',',cnt++;
	}
	cout<<'\n'<<cnt;
	return 0;
}

