#include<iostream>
const int mod=(int)1e9+5;
using namespace std;
inline long long ksm(long long b,long long p)
{
    if(p==0)
    return 1%mod;
    long long t=ksm(b,p/2);
    t=(t%mod)*(t%mod)%mod;
    if(p%2==1)
    t=(t%mod)*(b%mod)%mod;
    return t;
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<ksm(a,b);
}
