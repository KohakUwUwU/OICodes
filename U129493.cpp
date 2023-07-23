#include<iostream>
using namespace std;
struct fhjklafh
{
	int data;
	int x,y;
}f[2001][2001];
int n,m,map[2001][2001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&map[i][j]);
	f[1][1].data=0,f[1][1].x=1,f[1][1].y=1;
	for(int i=1;i<=m;i++)
	{
		if(map[i][1]<map[f[i-1][1].x][f[i-1][1].y])f[i][1].data=f[i-1][1].data+map[f[i-1][1].x][f[i-1][1].y],f[i][1].x=i,f[i][1].y=1;
		else f[i][1]=f[i-1][1];
	}
	for(int i=1;i<=n;i++)
	{
		if(map[1][i]<map[f[1][i-1].x][f[1][i-1].y])f[1][i].data=f[1][i-1].data+map[f[1][i-1].x][f[1][i-1].y],f[1][i].x=i,f[1][i].y=1;
		else f[1][i]=f[1][i-1];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			;
		}
	}
}
