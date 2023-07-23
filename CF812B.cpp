//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=20;
const int INF=114514114514;
int G[N*4][N*4];
int n,m,nVertex; 
inline void addEdge(int u,int v,int w)
{
	G[u][v]=w;
}
inline void Floyd()
{
	for(int k=1;k<=nVertex;k++)
	{
		for(int i=1;i<=nVertex;i++)
		{
			for(int j=1;j<=nVertex;j++)
			{
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
}
signed main()
{
	cin>>n>>m;
	m+=2;
	string str;
	nVertex=4*n;
	for(int i=1;i<=nVertex;i++)
	{
		for(int j=1;j<=nVertex;j++)
		{
			G[i][j]=INF;
		}
		G[i][i]=0;
	}
	int light=0;
	for(int i=n;i>=1;i--)
	{
		int first1=0,last1=0;
		string str;
		cin>>str;
		for(int j=0;j<str.length();j++)
		{
			if(str[j]=='0')continue;
			last1=j;
			if(!first1)first1=j;
		}
		int v1=(i-1)*4+1;
		int v2=(i-1)*4+2;
		int v3=(i-1)*4+3;
		int v4=(i-1)*4+4;
		int v5=(i-1)*4+5;
		int v6=(i-1)*4+6;
		if(!first1)
		{
			addEdge(v1,v5,1);
			addEdge(v2,v6,1);
			continue;
		}
		if(!light)light=i;
		addEdge(v1,v3,last1);
		addEdge(v2,v4,m-1-first1);
		addEdge(v3,v5,last1+1);
		addEdge(v4,v6,m-first1);
		addEdge(v3,v6,m-last1);
		addEdge(v4,v5,first1+1);
	}
//	for(int i=1;i<=nVertex;i++,cout<<endl)for(int j=1;j<=nVertex;j++)
//	{
//		if(G[i][j]!=INF)cout<<G[i][j]<<' ';
//		else cout<<"- ";
//	}
	nVertex=4*light;
	Floyd();
	cout<<min(G[1][nVertex],G[1][nVertex-1]);
	return 0;
}

