#include<bits/stdc++.h>
using namespace std;
int n,w,wi[301],vi[301];
double f[1001][3001];
double l,r=1000,ans=0,err=1e-5;
#define v(i,val) vi[i]-val*wi[i]
inline int bag(double x)
{
	f[0][0]=0;
	for(int i=1;i<=w;i++)f[0][i]=-11451411;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			int k=max(j-wi[i],0);
			if(f[i-1][k]==-11451411)f[i][j]=f[i-1][j];
			else f[i][j]=max(f[i-1][j],f[i-1][k]+v(i,x));
		}
	}
	return f[n][w]>=0;
}
int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>wi[i]>>vi[i];
	}
	while(r-l>err)
	{
		double mid=(l+r)/2;
		if(bag(mid))l=mid,ans=max(ans,mid);
		else r=mid;
	}
	cout<<int(ans*1000+0.5);
	return 0;
}
