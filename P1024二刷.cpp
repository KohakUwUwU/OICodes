//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
#define db long double
using namespace std;

db a,b,c,d;
inline double calc(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
signed main()
{
	cin>>a>>b>>c>>d;
	double last_root=-114514;
	for(int i=-100;i<=100;i++)
	{
		if(calc(i)*calc(i+1)>0)continue;
		double l=i,r=i+1;
		while(abs(r-l)>=1e-3)
		{
			double mid=(l+r)/2.0;
			if(calc(l)*calc(mid)<=0)r=mid;
			else l=mid;
		}
		if(abs(last_root-l)>0.9)cout<<fixed<<setprecision(2)<<l<<' ';
		last_root=l;
	}
	return 0;
}

