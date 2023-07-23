#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,c,f[1000][2001],w[1001],v[1001];
signed main()
{
	freopen("hunger.in","r",stdin);
	freopen("hunger.out","w",stdout);
	cin>>n>>c;
	f[0][0]=0;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=c;i++)f[0][i]=-11451411;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		for(int j=0;j<=c;j++)
		{
			int k=max(j-w[i],(long long)(0));
			if(f[i-1][k]==-11451411)f[i][j]=f[i-1][j];
			else f[i][j]=max(f[i-1][j],f[i-1][k]+v[i]);
		}
	}
	cout<<f[n][c];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
