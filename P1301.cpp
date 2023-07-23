#include<iostream>
#include<map>
using namespace std;
int n,m;
map<int,map<int,int> >G;
map<int,map<int,map<int,int> > >vis;
struct node
{
	int x,y,dir,step;
};
map<int,node>q;
int head=0,tail=1;
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)cin>>G[i][j];
	}
	q[head].x=1,q[head].y=1;q[head].dir=-1;q[head].step=0;
	vis[1][1][0]=1;vis[1][1][1]=1;vis[1][1][2]=1;vis[1][1][3]=1;vis[1][1][4]=1;vis[1][1][5]=1;vis[1][1][6]=1;vis[1][1][7]=1;
	while(head<tail)
	{
		for(int i=0;i<8;i++)
		{
			if(i==q[head].dir)continue;
			int xx=q[head].x+dx[i]*G[q[head].x][q[head].y];
			int yy=q[head].y+dy[i]*G[q[head].x][q[head].y];
			if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&!vis[xx][yy][q[head].dir])
			{
				vis[xx][yy][q[head].dir]=1;
				q[tail].x=xx;
				q[tail].y=yy;
				q[tail].dir=i;
				q[tail].step=q[head].step+1;
				if(q[tail].x==m&&q[tail].y==n)
				{
					if(q[tail].step!=8)cout<<q[tail].step;
					else cout<<7;
					return 0;
				}
				tail++;
			}
		}
		head++;
	}
	cout<<"NEVER";
}
