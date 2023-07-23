//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int isPrime(int n)
{
	if(n==2)return true;
	for(int i=2;i*i<=n;i++)if(n%i==0)return false;
	return true;
}
inline int last(int n)
{
	while(isPrime(n))n--;
	return n;
}
signed main()
{
	while(1)
	{
		int a;
		cin>>a;
		cout<<last(a);
	}
	return 0;
}

