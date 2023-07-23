#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,time;
}q[150000];
int head=0,tail=1;
int n;
int G[310][310];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
inline void init(int a,int b,int c)
{
	G[a][b]=G[a][b]==-1?c:min(G[a][b],c);
	G[a+1][b]=G[a+1][b]==-1?c:min(G[a+1][b],c);
	G[a][b+1]=G[a][b+1]==-1?c:min(G[a][b+1],c);
	if(a-1>=0)G[a-1][b]=G[a-1][b]==-1?c:min(G[a-1][b],c);
	if(b-1>=0)G[a][b-1]=G[a][b-1]==-1?c:min(G[a][b-1],c);
}
int main()
{
//	freopen("P2895_8.in","r",stdin);
//	freopen("P2895_8.out","w",stdout);
	memset(G,-1,sizeof(G));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		init(x,y,t);
	}
	if(G[0][0]==-1)
	{
		cout<<0;
		return 0;
	}
	q[head].x=0;q[head].y=0;q[head].time=0;G[0][0]=0;
	while(head<tail)
	{
		for(int i=0;i<4;i++)
		{
			int xx=q[head].x+dx[i];
			int yy=q[head].y+dy[i];
			int ttime=q[head].time+1;
			if(xx>=0&&yy>=0&&(G[xx][yy]==-1||ttime<G[xx][yy]))
			{
				if(G[xx][yy]==-1)
				{
					cout<<ttime;
//					fclose(stdin);
//					fclose(stdout);
					return 0;
				}
				q[tail].time=ttime;
				q[tail].x=xx;
				q[tail].y=yy;
				tail++;
				G[q[head].x][q[head].y]=0;
			}
		}
		head++;
	}
	cout<<-1;
	return 0;
}
