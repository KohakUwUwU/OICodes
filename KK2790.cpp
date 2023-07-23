//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=202;
int nSteps,nE,nV,s,t,id[N],f[21][N][N],h[N][N],g[N][N]; 
signed main()
{
//	freopen("patrol.in","r",stdin);
//	freopen("patrol.out","w",stdout);
	cin>>nSteps>>nE>>s>>t;
	memset(f,0x3f,sizeof(f));
	int u,v,w;
	for(int i=1;i<=nE;i++)
	{
		cin>>w>>u>>v;
		if(!id[u])id[u]=++nV;
		if(!id[v])id[v]=++nV;
		f[0][id[u]][id[v]]=min(f[0][id[u]][id[v]],w);
		f[0][id[v]][id[u]]=min(f[0][id[v]][id[u]],w);
	}
	for(int p=1;(1<<p)<=nSteps;p++)
	{
		for(int k=1;k<=nV;k++)
		{
			for(int i=1;i<=nV;i++)
			{
				for(int j=1;j<=nV;j++)
				{
					f[p][i][j]=min(f[p][i][j],f[p-1][i][k]+f[p-1][k][j]);
				}
			}
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int k=1;k<=nV;k++)g[k][k]=0;
	for(int p=0;(1<<p)<=nSteps;p++)
	{
		if(((1<<p)&nSteps)==0)continue;
		memset(h,0x3f,sizeof(h));
		for(int k=1;k<=nV;k++)
		{
			for(int i=1;i<=nV;i++)
			{
				for(int j=1;j<=nV;j++)
				{
					h[i][j]=min(h[i][j],g[i][k]+f[p][k][j]);
				}
			}
		}
		memcpy(g,h,sizeof(g));
	}
	cout<<h[s][t];
} 
