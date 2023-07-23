//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e3+5;
int n,m,a[N],f[N][N],max_f[N][N];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)max_f[i][j]=-114514114514;
	max_f[1][1]=max_f[0][1]=-114514114514;
	for(int i=1;i<=n;i++)max_f[i][0]=-114514114514;
	for(int i=1;i<=n;i++)f[i][1]=a[i],max_f[i][1]=max(max_f[i-1][1],f[i][1]);
	//f[i][j] i选，直至i选了j个数
	//f[i][j]=max(f[k][j-1])+a[i]*j;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=i;j++)
		{
			f[i][j]=max_f[i-1][j-1]+a[i]*j;
			max_f[i][j]=max(max_f[i-1][j],f[i][j]);
		}
	}
	int ans=-114514114514;
	for(int i=m;i<=n;i++)ans=max(ans,f[i][m]);
	cout<<ans<<' ';
	return 0;
}

