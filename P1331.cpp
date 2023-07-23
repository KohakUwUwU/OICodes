#include<iostream>
using namespace std;
char map[10001][10001];
int r,c,sum=0;
void dfs(int x,int y)
{
	if(x+1<=c&&map[x+1][y]=='#')map[x+1][y]='.',dfs(x+1,y);
	if(x-1>=1&&map[x-1][y]=='#')map[x-1][y]='.',dfs(x-1,y);
	if(y+1<=c&&map[x][y+1]=='#')map[x][y+1]='.',dfs(x,y+1);
	if(y-1>=1&&map[x][y-1]=='#')map[x][y-1]='.',dfs(x,y-1);
}
int main()
{
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	{
		string str;
		cin>>str;
		for(int j=1;j<=c;j++)
		{
			map[i][j]=str[j-1];
		}
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(map[i][j]=='#')
			{
				sum++;
				map[i][j]='.';
				dfs(i,j);
			}
		}
	}
	cout<<sum;
}
