//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+5,INF=9223372036854775807;
int n,k,t[N],x[N],y[N];
inline void WRONG()
{
	printf("Mystia will cook forever...");
}
inline int gcd(int x,int y)
{
//	cout<<x<<' '<<y<<'\n';
	if(x<y)swap(x,y);
	if(!y)return x;
	return gcd(x%y,y);
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>t[i]>>x[i]>>y[i];
	if(k==1)
	{
		WRONG();
		return 0;
	}
	bool RIGHT=false;
	int ans=INF;
	for(int i=1;i<=k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
//			cout<<"t:"<<'\n'<<t[i]<<' '<<t[j]<<'\n';
			int g=gcd(t[i],t[j]);
//			cout<<"g:"<<'\n'<<g<<'\n';
			int xi=t[j]/g,xj=t[i]/g;
//			cout<<"x:"<<'\n'<<xi<<' '<<xj<<'\n';
			for(int k=1;k<=10;k++)
			{
				int in=((xi*k-1)*y[i]+x[i])%n,jn=((xj*k-1)*y[j]+x[j])%n;
//				cout<<"n:"<<'\n'<<in<<' '<<jn<<'\n';
				if(in!=jn)ans=min(ans,t[i]*t[j]*k/g),RIGHT=true;
			}
		}
	}
	if(!RIGHT)
	{
		WRONG();
		return 0;
	}
	cout<<ans-1;
	return 0;
}

