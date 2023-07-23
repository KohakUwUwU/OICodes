//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=55;
int t,n,turn;
int ma[N][N],f[N][N][3][5];
//f[i][j][k][l]
//(i,j)为坐标
//k为上一次转移过来时方向(0朝右1朝下)
//l为转向次数 
signed main()
{
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		cin>>n>>turn;
		for(int i=1;i<=n;i++)
		{
			string str;
			cin>>str;
			for(int j=0;j<str.length();j++)ma[i][j+1]=(str[j]=='H');
		}
		f[1][1][0][0]=f[1][1][1][0]=1;
		for(int i=2;i<=n;i++)f[i][1][1][0]=(ma[i][1])?0:f[i-1][1][1][0];
		for(int j=2;j<=n;j++)f[1][j][0][0]=(ma[1][j])?0:f[1][j-1][0][0];
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				for(int k=0;k<=1;k++)
				{
					for(int l=0;l<=turn;l++)
					{
						//i j 1 l
						//i-1 j 0 l-1
						//i-1 j 1 l
						//i j-1 0 l
						//i j-1 1 l-1
//						cout<<i<<' '<<j<<' '<<k<<' '<<l<<' ';
						if(ma[i][j])continue;
//						f[i][j][k][l]+=((l-k>=0)?f[i-1][j][0][l-k]:0);cout<<f[i][j][k][l]<<' ';
//						f[i][j][k][l]+=((l-(k^1)>=0)?f[i-1][j][1][l-(k^1)]:0);cout<<f[i][j][k][l]<<' ';
//						f[i][j][k][l]+=((l-(k^1)>=0)?f[i][j-1][0][l-(k^1)]:0);cout<<f[i][j][k][l]<<' ';
//						f[i][j][k][l]+=((l-k>=0)?f[i][j-1][1][l-k]:0);cout<<f[i][j][k][l]<<'\n';
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
				}
			}
		}
		int ans=0;
		for(int k=0;k<=1;k++)for(int l=0;l<=turn;l++)ans+=f[n][n][k][l];
		cout<<ans<<'\n';
	}
	return 0;
}

