#include<bits/stdc++.h>
using namespace std;
#define int long long
//POPPIN PARTY
//By TOYOTA KASUMI
inline int read()
{
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1003];
int f[1003];
int fac[2003],ifac[2003];
int C(int n,int m)
{
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
signed main()
{
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	fac[0]=ifac[0]=1;
	for(int i=1; i<=2000; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
    int n=read(),m=read();
    for(int i=1; i<=m; ++i) a[i]=read();
    f[1]=1;
    for(int i=2; i<=n; ++i)
    {
    	int S=1;
    	for(int j=1; j<=m; ++j) S=S*C(a[j]+i-1,i-1)%p;
    	f[i]=S;
    	for(int j=1; j<i; ++j) f[i]=(f[i]+p-f[j]*C(i,j)%p)%p;
    }
    printf("%lld\n",f[n]);
	return 0;
}
