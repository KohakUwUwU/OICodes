#include<iostream>
using namespace std;
int l[510][510],r[510][510],m,n,ma[510][510],v[510],vis[510][510],cnt;
bool judge(int x1,int y1,int x2,int y2)
{
	if(ma[x1][y1]>ma[x2][y2]&&!vis[x2][y2])return true;
	else return false;
}
void dfs(int x,int y)
{
	if(y==m)v[x]=1;
	if(x+1>0&&x+1<=m&&judge(x,y,x+1,y))vis[x+1][y]=1,l[x][y]=min(l[x][y],l[x+1][y]),r[x][y]=max(r[x][y],r[x+1][y]),dfs(x+1,y),vis[x+1][y]=0;
	if(x-1>0&&x-1<=m&&judge(x,y,x-1,y))vis[x+1][y]=1,l[x][y]=min(l[x][y],l[x-1][y]),r[x][y]=max(r[x][y],r[x-1][y]),dfs(x-1,y),vis[x-1][y]=0;
	if(y+1>0&&y+1<=n&&judge(x,y,x,y+1))vis[x][y+1]=1,l[x][y]=min(l[x][y],l[x][y+1]),r[x][y]=max(r[x][y],r[x][y+1]),dfs(x,y+1),vis[x][y+1]=0;
	if(y-1>0&&y-1<=n&&judge(x,y,x,y-1))vis[x][y-1]=1,l[x][y]=min(l[x][y],l[x][y-1]),r[x][y]=max(r[x][y],r[x][y-1]),dfs(x,y-1),vis[x][y-1]=0;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)l[n][i]=r[n][i]=i;
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cin>>ma[i][j];
	for(int i=1;i<=n;i++)if(!vis[1][i])vis[1][i]=1,dfs(1,i);
	bool f=false;
	for(int i=1;i<=n;i++)if(v[i]==0)f=true,cnt++;
	if(f)
	{
		cout<<0<<endl<<cnt;
		return 0;
	}
	int ll=1;
	while(ll<=n)
	{
		int mr=0;
		for(int i=1;i<=n;i++)if(l[1][i]<=ll)mr=max(mr,r[1][i]);
		cnt++;
		ll=mr+1;
	}
	cout<<1<<endl<<cnt;
}//correct nm
