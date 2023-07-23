//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=25;
int n,m,g[N][N],f[1<<20][N];
inline void addEdge(int u,int v,int w)
{
	g[u][v]=g[v][u]=w;
}
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)cin>>g[i][j];
	}
	memset(f,0x3f,sizeof(f));
	f[1][0]=0;
	for(int i=0;i<(1<<n);i++)//枚举二进制状态 
	{
		for(int j=0;j<n;j++)//枚举这次可能到达的位置 
		{
			if(i>>j&1)//判断当前位置是否可达（即当前状态此位置为1） 
			{
				for(int k=0;k<n;k++)//枚举上一次所在的位置 
				{
					if((i^(1<<j))>>k&1)//判断上次所在的位置是否合法（即判断这个点是否被经过） 
					{
						f[i][j]=min(f[i][j],f[i^(1<<j)][k]+g[j][k]);
					}
				}
			}
		}
	}
	cout<<f[(1<<n)-1][n-1];
	return 0;
}