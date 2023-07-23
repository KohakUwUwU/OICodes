#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=51;
int t,n,turn;
int ma[N][N],f[N][N][3][5];
signed main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>turn;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			string str;
			cin>>str;
			for(int j=0;j<str.length();j++)ma[i][j+1]=(str[j]=='H');
		}
		f[1][1][0][0]=f[1][1][1][0]=1;
		for(int i=2;i<=n;i++)f[i][1][1][0]=(ma[i][1])?0:f[i-1][1][1][0];
		for(int j=2;j<=n;j++)f[1][j][0][0]=(ma[1][j])?0:f[1][j-1][0][0];
		for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)for(int k=0;k<=1;k++)for(int l=0;l<=turn;l++)
		{
			if(ma[i][j])continue;
			if(k==0)
			{
				f[i][j][k][l]=f[i][j-1][0][l];
				if(l-1>=0)f[i][j][k][l]+=f[i][j-1][1][l-1];
			}
			else
			{
				f[i][j][k][l]=f[i-1][j][1][l];
				if(l-1>=0)f[i][j][k][l]+=f[i-1][j][0][l-1];
			}
		}
		int ans=0;
		for(int k=0;k<=1;k++)for(int l=0;l<=turn;l++)ans+=f[n][n][k][l];
		cout<<ans<<'\n';
	}
	return 0;
}
