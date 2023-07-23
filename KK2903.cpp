//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=20;
const long double eps=1e-8;
int n;
long double ma[N][N],a[N][N],b[N];
signed main()
{
	freopen("sphere.in","r",stdin);
	freopen("sphere.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;i++)for(int j=1;j<=n;j++)cin>>ma[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		a[i][j]=2*(ma[i][j]-ma[i+1][j]),
		b[i]+=ma[i][j]*ma[i][j]-ma[i+1][j]*ma[i+1][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(fabs(a[i][j])>eps)
			{
				for(int k=1;k<=n;k++)swap(a[i][k],a[j][k]);
				swap(b[i],b[j]);
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			long double r=a[j][i]/a[i][i];
			for(int k=i;k<=n;k++)a[j][k]-=a[i][k]*r;
			b[j]-=b[i]*r;
		}
	}
	for(int i=1;i<=n;i++)cout<<fixed<<setprecision(3)<<b[i]/a[i][i]<<' ';
	return 0;
}

