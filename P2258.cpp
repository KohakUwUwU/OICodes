//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=20;
int n,m,r,c,a[N][N],b[N][N],f[N][N],q[N],ins[N],ans=114514114514;
//question: the minimum value of a matrix
//value: the sum of the absolute value of all of the element pair
//a[i][j] original value
//b[i][j] dp value
//f[i][k]=min{f[j][k-1]+dis(i,j)+inside(i)}
//dis(i,j)=sigma(abs(b[k][i]-b[k][j]) ava=calc
//inside(i)=sigma(abs(b[j][i]-b[j+1][i]) ava=O1
inline int dis(int i,int j)
{
	int ans=0;
	for(int k=1;k<=r;k++)ans+=abs(b[k][i]-b[k][j]);
	return ans;
}
inline int inside(int i)
{
	return ins[i];
}
inline void print()
{
	for(int i=1;i<=r;i++)cout<<q[i]<<" ";
	cout<<'\n';
	cout<<"b:\n";
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=m;j++)cout<<b[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"ins:\n";
	for(int i=1;i<=m;i++)cout<<ins[i]<<' ';
	cout<<'\n';
	cout<<"f:\n";
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=c;j++)cout<<"f["<<i<<"]["<<j<<"]="<<f[i][j]<<' ';
		cout<<'\n';
	}
}
inline void run()
{
	memset(b,0,sizeof(b));
	memset(ins,0,sizeof(ins));
	for(int i=0;i<=max(n,m);i++)
	{
		for(int j=0;j<=max(n,m);j++)f[i][j]=114514114514;
	}
	for(int ii=1;ii<=r;ii++)
	{
		int i=q[ii];
		for(int j=1;j<=m;j++)
		{
			b[ii][j]=a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<r;j++)ins[i]+=abs(b[j][i]-b[j+1][i]);
	}
	for(int i=1;i<=m;i++)f[i][0]=0;
	for(int i=1;i<=m;i++)f[i][1]=inside(i);
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int k=2;k<=i;k++)
			{
//				cout<<i<<' '<<j<<' '<<k<<' '<<f[i][k]<<' '<<f[j][k-1]<<' '<<dis(i,j)<<' '<<inside(i)<<' '<<f[j][k-1]+dis(i,j)+inside(i)<<' ';
				f[i][k]=min(f[i][k],f[j][k-1]+dis(i,j)+inside(i));
				//前i个以i结尾选k个的答案：依赖(j,k-1) 
			}
		}
	}
	//2,2 1,1
	//
//	print();
//	cout<<'\n';
	for(int i=c;i<=m;i++)ans=min(ans,f[i][c]);
}
inline void dfs(int step)
{
	if(step==r+1)
	{
		run();
		return ;
	}
	for(int i=q[step-1]+1;i<=n;i++)
	{
		q[step]=i;
		dfs(step+1);
	}
}
signed main()
{
	cin>>n>>m>>r>>c;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	dfs(1);
	cout<<ans;
	return 0;
}

