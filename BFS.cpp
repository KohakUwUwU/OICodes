#include<iostream>
using namespace std;
int m,n,map[1001][1001],vis[1001][1001],sx,sy,ex,ey;
struct node
{
	int x,y,step;
}q[100001];
int head=0,tail=1;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main()
{
	cin>>m>>n;
	cin>>sx>>sy>>ex>>ey;
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cin>>map[i][j];
	vis[sx][sy]=1;
	
	q[head].x=sx;q[head].y=sy;q[head].step=0;
	while(head<tail)
	{
		for(int i=0;i<4;i++)
		{
			int xx=q[head].x+dx[i];
			int yy=q[head].y+dy[i];
			if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&map[xx][yy]==0&&vis[xx][yy]==0)
			{
				vis[xx][yy]=1;
				q[tail].x=xx;
				q[tail].y=yy;
				q[tail].step=q[head].step+1;
				if(xx==ex&&yy==ey)
				{
					cout<<q[tail].step;
					return 0;
				}
				tail++;
			}
		}
		head++;
	}
	cout<<"no";
	return 0;
}
