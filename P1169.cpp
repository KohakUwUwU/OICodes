#include<iostream>
using namespace std;
int m,n,map[2001][2001],pos[2001][2001][2],f[2001][2001];
int main()
{
	cin>>n>>m;
	memset(map,3,sizeof(map));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>map[i][j];
			int up=0,down=0;
			if(map[i-1][j]!=map[i][j]&&map[i][j-1]!=map[i][j])
			{
				f[i][j]=1;
				pos[i][j][0]=i;pos[i][j][1]=j;
			}
			else if(map[i-1][j]!=map[i][j])
		}
	}
}
