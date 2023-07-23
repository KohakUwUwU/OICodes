#include<iostream>
#define mod 998244353
#define int long long
using namespace std;
inline int fastpow(int k,int n)
{
	if(n==0)return 1;
	if(n==1)return 2;
	int c=fastpow(k,n/2);
	if(n&1)return c*c%mod*k%mod;
	else return c*c%mod;
}
inline int s1(int n)
{
	return (-2*n%mod+3*(fastpow(2,n)-1)%mod)%mod;
}
inline int kth(int n)
{
	return (1+3*(fastpow(2,n-1)-1))%mod;
}
inline int s2(int n,int q)
{
	return q+(q*2+1)*((fastpow(2,n-1)-1))%mod;
}
inline int ans(int s,int l,int r)
{
	if(l>s)
	{
		cout<<s2(r,1)-s2(l-1,r)<<'\n';
	}
	else
	{
		cout<<s1(s)-s1(l-1)+s2(r,kth(s))-s2(s-1,kth(s))<<'\n';
	}
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int s,l,r;
		cin>>s>>l>>r;
		cout<<ans(s,l,r);
	}
}
