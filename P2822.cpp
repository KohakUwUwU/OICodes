//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e3+5;
int t,k,n,m,yh[N][N],mok[N][N];
inline void pre()
{
	for(int i=0;i<=2000;i++)yh[i][0]=1%k;
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<=i;j++)(yh[i][j]=yh[i-1][j]+yh[i-1][j-1])%=k;
	}
//	for(int i=0;i<=20;i++)
//	{
//		for(int j=0;j<=20;j++)
//		{
//			cout<<yh[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	mok[0][0]=(yh[0][0]==0);
	for(int i=1;i<=2000;i++)mok[i][0]=mok[i-1][0]+(yh[i][0]==0);
	for(int j=1;j<=2000;j++)
	{
		mok[j][j]=mok[j][j-1]+(yh[j][j]==0);
		for(int i=j+1;i<=2000;i++)
		{
			mok[i][j]=mok[i][j-1]+mok[i-1][j]-mok[i-1][j-1]+(yh[i][j]==0);
		}
	}
}
signed main()
{
	cin>>t>>k;
	pre();
	while(t--)
	{
		cin>>n>>m;
		m=min(n,m);
		cout<<mok[n][m]<<'\n';
	}
	return 0;
}

