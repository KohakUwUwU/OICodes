#include<bits/stdc++.h>
#define int long long
#define double long double
//RAISE A SUILEN
//All Rights Reserved
//By CHUCHU
using namespace std;
inline int read()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*w;
}

int y;
inline double F(double x)
{
	return x*x*x*x*x*x*(x+1)+x*x*(x+1)-x*y;
}
signed main()
{
	freopen("convex.in","r",stdin);
	freopen("convex.out","w",stdout);
	int t=read();
	while(t--)
	{
		y=read();double mn=11451411;
		for(double i=0.0,val;i<=2.0;i+=0.0001)val=F(i),mn=min(mn,val);
		cout<<fixed<<setprecision(3)<<mn<<'\n';
	}
	return 0;
}

