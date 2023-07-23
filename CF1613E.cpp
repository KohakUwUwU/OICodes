//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+6;
int t,n,m,sx,sy;
map<int,map<int,int> >vis;
int now;//当前运行时间戳，避免vis要多次清空 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
string ma[N];
queue<pair<int,int> >q;
inline int dir(int x,int y)
{
	int ans=0;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<0||xx>=n||yy<0||yy>=m)continue;
		if(vis[xx][yy]==now||ma[xx][yy]=='#')continue;
		ans++;
	}
	return ans;
}
inline void Move(int& x,int& y)
{
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<0||xx>=n||yy<0||yy>=m)continue;
		if(vis[xx][yy]==now||ma[xx][yy]=='#')continue;
		x=xx,y=yy;
		return ;
	}
}
inline void Work()
{
	for(int i=0;i<n;i++)
	{
		int b=0;
		for(int j=0;j<m;j++)
		{
			if(ma[i][j]=='L')
			{
				sx=i,sy=j;
				b=1;
				break;
			}
		}
		if(b)break;
	}
	vis[sx][sy]=now;
	for(int i=0;i<4;i++)
	{
		int xx=sx+dx[i],yy=sy+dy[i];
		if(xx<0||xx>=n||yy<0||yy>=m)continue;
		if(ma[xx][yy]=='#')continue;
		if(dir(xx,yy)!=1)continue;
		q.push(make_pair(xx,yy));
	}
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		vis[x][y]=now;
		ma[x][y]='+';
		while(dir(x,y)==1)
		{
			vis[x][y]=now;
			ma[x][y]='+';
			Move(x,y);
		}
		if(dir(x,y)==0)
		{
			if(x<0||x>=n||y<0||y>=m)continue;
			if(ma[x][y]=='#')continue;
			vis[x][y]=now;
			ma[x][y]='+';
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<ma[i][j];
		}
		cout<<'\n';
	}
}
signed main()
{
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)cin>>ma[i];
		now=i;
		Work();
	}
	return 0;
}
