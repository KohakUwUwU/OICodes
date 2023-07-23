#include<iostream>
#define N 1005
using namespace std;
struct node
{
	int x,y;
}fa[N][N];
int n,m,ma[N][N],vis[N][N],cnt[N][N];
string str;
inline bool gs(int x,int y)
{
	return x==fa[x][y].x&&y==fa[x][y].y;
}
inline node Find(int x,int y)
{
	return gs(x,y)?node{x,y}:(fa[x][y]=Find(fa[x][y].x,fa[x][y].y));
}
inline void Merge(int x1,int y1,int x2,int y2)
{
	node x=Find(x1,y1),y=Find(x2,y2);
	fa[x.x][x.y]=node{y.x,y.y};
}
inline void dfs(int x,int y)
{
	if(ma[x][y]!=ma[x+1][y]&&!vis[x+1][y])vis[x+1][y]=1,Merge(x,y,x+1,y),dfs(x+1,y);
	if(ma[x][y]!=ma[x-1][y]&&!vis[x-1][y])vis[x-1][y]=1,Merge(x,y,x-1,y),dfs(x-1,y);
	if(ma[x][y]!=ma[x][y+1]&&!vis[x][y+1])vis[x][y+1]=1,Merge(x,y,x,y+1),dfs(x,y+1);
	if(ma[x][y]!=ma[x][y-1]&&!vis[x][y-1])vis[x][y-1]=1,Merge(x,y,x,y-1),dfs(x,y-1);
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		for(int j=0;j<str.length();j++)ma[i][j]=str[j];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!vis[i][j])
			{
				vis[i][j]=1;
				dfs(i,j);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			node x=Find(i,j);
			++cnt[x.x][x.y];
		}
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		node xx=Find(x,y);
		cout<<cnt[xx.x][xx.y]<<'\n';
	}
}
