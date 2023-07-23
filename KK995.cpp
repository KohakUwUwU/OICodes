//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e2+5;
int n,m,ans,h[N][N],vst[N][N];
struct node
{
	int x,y;
	bool operator<(const node&a)const
	{
		return h[x][y]>h[a.x][a.y];
	}
};
inline void bfs()
{
	priority_queue<node>q;
	for(int j=1;j<=m;j++)
	{
		q.push((node){1,j});
		q.push((node){n,j});
		vst[1][j]=vst[n][j]=1;
	}
	for(int i=1;i<=n;i++)
	{
		q.push((node){i,1});
		q.push((node){i,m});
		vst[i][1]=vst[i][m]=1;
	}
	while(!q.empty())
	{
		int x=q.top().x,y=q.top().y;
//		cout<<x<<' '<<y<<' ';
		q.pop();
		int dx[4]={1,-1,0,0};
		int dy[4]={0,0,1,-1};
		for(int k=0;k<4;k++)
		{
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vst[nx][ny])
			{
				if(h[x][y]>h[nx][ny])
				{
					ans+=h[x][y]-h[nx][ny];
					h[nx][ny]=h[x][y];
				}
				vst[nx][ny]=1;
				q.push((node){nx,ny});
			}
		}
//		cout<<ans<<'\n';
	}
}
signed main()
{
	freopen("storm3.in","r",stdin);
	freopen("storm3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>h[i][j];
		}
	}
	bfs();
	cout<<ans;
	return 0;
}

