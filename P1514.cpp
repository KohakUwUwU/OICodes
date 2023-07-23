#include<iostream>
#include<map>
using namespace std;
int n,m;
map<int,map<int,int> > G;
map<int,map<int,int> > s;
int cnt[501];
void dfs(int set,int x,int y)
{
	if(y==n)s[set][x]=1,cnt[set]++;
	if(x+1>0&&x+1<=m&&y>0&&y<=n&&G[x][y]>G[x+1][y])dfs(set,x+1,y);
	if(x-1>0&&x-1<=m&&y>0&&y<=n&&G[x][y]>G[x-1][y])dfs(set,x-1,y);
	if(x>0&&x<=m&&y+1>0&&y+1<=n&&G[x][y]>G[x][y+1])dfs(set,x,y+1);
	if(x>0&&x<=m&&y-1>0&&y-1<=n&&G[x][y]>G[x][y-1])dfs(set,x,y-1);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)cin>>G[i][j];
	}
	for(int i=1;i<=m;i++)
	{
		dfs(i,i,1);
	}
	while()
}
