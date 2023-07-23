#include<iostream>//WA
#define N 105
#define R register
using namespace std;
int mx=-1,n,m,G[N][N],f[N][N][2];//f i j 0: length 1:state{0-> no plug 1-> down to here 2->up to here}
#define check(a,b,c,d) G[a][b]>G[c][d]?1:2
#define reverse(a) a==1?2:1
#define update(a) mx>a?mx:a
inline void dp(R int x,R int y)
{
	R int t1,t2,t1t,t2t;
	if(check(x-1,y,x,y)==f[x-1][y][1])t1=f[x-1][y][0]+1,t1t=f[x-1][y][1];
	else t1=2,t1t=reverse(f[x-1][y][1]);
	if(check(x,y-1,x,y)==f[x][y-1][1])t1=f[x][y-1][0]+1,t1t=f[x][y-1][1];
	else t1=2,t1t=reverse(f[x][y-1][1]);
	if(t1>t2)f[x][y][0]=t1,f[x][y][1]=t1t;
	else f[x][y][0]=t2,f[x][y][1]=t2t;
}
int main()
{
	cin>>n>>m;
	for(R int i=1;i<=n;i++)for(R int j=1;j<=m;j++)
	{
		cin>>G[i][j];
	}
	f[1][1][0]=1;f[1][1][1]=0;
	f[2][1][0]=2;f[2][1][1]=(G[1][1]>G[2][1]?1:0);
	f[1][2][0]=2;f[1][2][1]=(G[1][1]>G[1][2]?1:0);
	for(R int i=3;i<=n;i++)
	{
		if(check(i-1,1,i,1)==f[i-1][1][1])
		{
			f[i][1][0]=f[i-1][1][0]+1;
			f[i][1][1]=f[i-1][1][1];
		}
		else
		{
			f[i][1][0]=2;
			f[i][1][1]=check(i-1,1,i,1);
		}
		update(f[i][1][0]);
	}
	for(R int i=3;i<=m;i++)
	{
		if(check(1,i-1,1,i)==f[1][i-1][1])
		{
			f[1][i][0]=f[1][i-1][0]+1;
			f[1][i][1]=f[1][i-1][1];
		}
		else
		{
			f[1][i][0]=2;
			f[1][i][1]=check(1,i-1,1,i);
		}
		update(f[1][i][0]);
	}
	for(R int i=2;i<=n;i++)
	{
		for(R int j=2;j<=m;j++)
		{
			dp(i,j);
			update(f[i][j][0]);
		}
	}
	cout<<mx;
}
