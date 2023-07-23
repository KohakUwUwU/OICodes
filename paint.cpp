#include<iostream>
#include<cstring>
#include<map>
using namespace std;
long long n,m,k,p,q,g[100001][1001],ans[1001],answer;
int a,b;
int sx,sy,ex,ey;
struct node
{
	int x,y,time,pathnum;
	map<int,map<int,int> >path;
}que[10001];
int last[10001][10001];
int head=0,tail=1;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool findx(int set,int fx,int fy)
{
	for(int i=1;i<=que[set].pathnum;i++)
	{
		if(que[set].path[i][0]==fx&&que[set].path[i][1]==fy)return false;
	}
	return true;
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>n>>m>>k>>p>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>g[i][j];
		}
	}
	cin>>a>>b;
	for(int i=1;i<=k;i++)
	{
		sx=a;sy=b;
		ex=(i*p+q)%n+1;ey=(i*q+p)%m+1;
//		cout<<ex<<" "<<ey<<endl;
		memset(que,0,sizeof(que));
		memset(last,-1,sizeof(last));
		head=0;tail=1;
		que[head].x=sx;que[head].y=sy;que[head].time=0;
		while(head<tail)
		{
			for(int i=0;i<4;i++)
			{
				int xx=que[head].x+dx[i];
				int yy=que[head].y+dy[i];
				if(findx(head,xx,yy)&&xx>=1&&xx<=n&&yy>=1&&yy<=m&&(last[ex][ey]==-1||last[ex][ey]!=-1&&g[que[head].x][que[head].y]!=g[que[tail].x][que[tail].y]&&que[head].time+1<last[ex][ey]||last[ex][ey]!=-1&&g[que[head].x][que[head].y]==g[que[tail].x][que[tail].y&&que[head].time<last[ex][ey]]))
				{
//					if(last[q[head].x][q[head].y]==-1)
//					{
						que[tail].x=xx;
						que[tail].y=yy;
						que[tail].time=que[head].time;
						que[tail].pathnum=que[head].pathnum+1;
//						que[tail].path=que[head].path;
						que[tail].path=que[head].path;
						que[tail].path[que[tail].pathnum][0]=xx;
						que[tail].path[que[tail].pathnum][1]=yy;
						if(g[que[head].x][que[head].y]!=g[que[tail].x][que[tail].y])que[tail].time++;
						if(last[xx][yy]==-1)last[xx][yy]=que[tail].time;
						else last[xx][yy]=min(last[xx][yy],que[tail].time);
//						cout<<"last"<<xx<<" "<<yy<<" "<<last[xx][yy]<<endl;
//					}
//					else
//					{
//						q[tail].x=xx;
//						q[tail].y=yy;
//						q[tail].time=min(q[head].time,last[q[head].x][q[head].y]);
//						if(map[q[head].x][q[head].y]!=map[q[tail].x][q[tail].y])q[tail].time++;
//						last[xx][yy]=min();
//					}
					tail++;
				}
			}
			head++;
		}
		ans[++ans[0]]=last[ex][ey];
	}
	answer=ans[1];
	for(int i=2;i<=ans[0];i++)
	{
		answer^=ans[i];
	}
	cout<<answer<<endl;
	return 0;
}
