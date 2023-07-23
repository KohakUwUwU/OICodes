#include<iostream>
using namespace std;
int m,n,sx,sy,ex,ey;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int map[1001][1001],vis[1001][1001];
bool f=false;
inline void dfs(int x,int y)
{
	if(x==ex&&y==ey)
	{
		f=true;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&map[xx][yy]==0&&vis[xx][yy]==0)
		{
			vis[xx][yy]=1;
			dfs(xx,yy);
			vis[xx][yy]=0;
		}
	}
}
int main()
{
	cin>>m>>n;
	cin>>sx>>sy>>ex>>ey;
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cin>>map[i][j];
	vis[sx][sy]=1;
	dfs(sx,sy);
	if(f)cout<<"yes";
	else cout<<"no";
}
