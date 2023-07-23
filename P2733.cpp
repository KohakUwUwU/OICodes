//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=255;
int n,hor[N][N],ver[N][N],cnt[N];
int f[N][N][N];//边长为i，以(j,k)为右下角的正方形是否成立 
inline void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<f[1][i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<hor[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<ver[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<f[2][i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		for(int j=1;j<=n;j++)
		{
			f[1][i][j]=str[j-1]-'0';
			if(f[1][i][j])
			{
				hor[i][j]=hor[i][j-1]+f[1][i][j];
				ver[i][j]=ver[i-1][j]+f[1][i][j];
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<=n;k++)
			{
				if(f[i-1][j-1][k-1]&&hor[j][k]>=i&&ver[j][k]>=i)f[i][j][k]=1,cnt[i]++;
			}
		}
	}
//	print();
	for(int i=2;i<=n;i++)if(cnt[i])cout<<i<<' '<<cnt[i]<<'\n';
	return 0;
}

