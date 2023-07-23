//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7,N=1e6+5;
int cases,n,m,fac[N],s[N];
inline int pow(int x,int y)
{
    int res=1;
    while(y)
	{
        if(y&1)res=res*x%mod;
        x=x*x%mod,y>>=1;
    }
	return res;
}
inline int C(int x,int y){return fac[x]*pow(fac[x-y],mod-2)%mod*pow(fac[y],mod-2)%mod;}
signed main()
{
	cin>>cases; 
	fac[0]=s[1]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    for(int i=2;i<N;i++)s[i]=(s[i-1]+s[i-2])*i%mod;
    while(cases--)
	{
        cin>>n>>m;
        cout<<C(n,m)*s[n-m-1<0?1:n-m-1]%mod<<'\n';
    }
    return 0;
}//4071
