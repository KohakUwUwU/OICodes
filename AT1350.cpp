#include<iostream>
using namespace std;
int m,n;
char map[510][510];
bool vis[510][510];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int sx,sy,ex,ey;
bool ans=false;
inline void dfs(int x,int y)
{
	if(x==ex&&y==ey)
	{
		ans=true;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&vis[xx][yy]==false&&map[xx][yy]!='#')
		{
			vis[xx][yy]=true;
			dfs(xx,yy);
			vis[xx][yy]=false;
		}
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
	{
		cin>>map[i][j];
		if(map[i][j]=='s')sx=i,sy=j;
		else if(map[i][j]=='g')ex=i,ey=j;
	}
	vis[sx][sy]=1;
	dfs(sx,sy);
	if(ans==true)cout<<"Yes";
	else cout<<"No";
}
