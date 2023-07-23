//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e3+5;
const int MOD=998244353;
struct Dot
{
	int x,y;
}d1,d2;
int n,m,x,y,in1,in2,in3,in4,f[N][N];
int dx[10]={0,0,0,0,1,1,1,2,2,3};
int dy[10]={0,3,2,1,2,1,0,1,0,0};
inline bool check(int p,int q)
{
	int alln=n*x+(n-1),allm=m*y+(m-1);
	if(1<=p&&p<=alln&&1<=q&&q<=allm)return true;
	return false;
}
signed main()
{
	freopen("lovelive.in","r",stdin);
	freopen("lovelive.out","w",stdout);
	cin>>n>>m>>x>>y;
	cin>>in1>>in2>>in3>>in4;
	d1.x=(in1-1)*(x+1)+in3;
	d1.y=(in2-1)*(y+1)+in4;
	cin>>in1>>in2>>in3>>in4;
	d2.x=(in1-1)*(x+1)+in3;
	d2.y=(in2-1)*(y+1)+in4;
	if(d1.x>d2.x)swap(d1,d2);
	f[d1.x][d1.y]=1;
	if(d1.y<d2.y)
	{
		for(int i=d1.x;i<=d2.x;i++)
		{
			for(int j=d1.y;j<=d2.y;j++)
			{
				if(i%(x+1)==0||j%(y+1)==0)continue;
				for(int k=1;k<=9;k++)
				{
					int xx=i+dx[k];
					int yy=j+dy[k];
					if(!check(xx,yy)||xx%(x+1)==0||yy%(y+1)==0)continue;
					f[xx][yy]+=f[i][j];
					f[xx][yy]%=MOD;
				}
			}
		}
	}
	else
	{
		for(int i=d1.x;i<=d2.x;i++)
		{
			for(int j=d1.y;j>=d2.y;j--)
			{
				if(i%(x+1)==0||j%(y+1)==0)continue;
				for(int k=1;k<=9;k++)
				{
					int xx=i+dx[k];
					int yy=j-dy[k];
					if(!check(xx,yy)||xx%(x+1)==0||yy%(y+1)==0)continue;
					f[xx][yy]+=f[i][j];
					f[xx][yy]%=MOD;
				}
			}
		}
	}
	cout<<f[d2.x][d2.y];
	return 0;
}

