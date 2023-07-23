//LizPlum
#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
const int INF=11451419;
struct Opt
{
	int v,k;
}f[N][N];
struct what
{
	int x,y;
}p[N];
int n;
inline int F(int i,int j,int k)
{
	int cost=p[k+1].x-p[i].x+p[k].y-p[j].y;
	return f[i][k].v+f[k+1][j].v+cost; 
}
signed main()
{
	freopen("construction.in","r",stdin);
	freopen("construction.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
	for(int i=1;i<=n-1;i++)f[i][i+1]=(Opt){F(i,i+1,i),i};
	for(int i=n-2;i>=1;i--)
	{
		for(int j=i+2;j<=n;j++)
		{
			f[i][j]=(Opt){INF,-1};
			int l=f[i][j-1].k,r=f[i+1][j].k;
			for(int k=l;k<=r;k++)
			{
				int v=F(i,j,k);
				if(v<=f[i][j].v)f[i][j]=(Opt){v,k};
			}
		}
	}
	cout<<f[1][n].v<<'\n';
	return 0;
}

