//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int a[N],n;
int vis[N],q[4][N];
inline int test(int k)
{
	int cnt=0,qc=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n/k;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		q[k][++qc]=i;
		for(int j=i*k;j<=n;j*=k)vis[j]=1,cnt++,q[k][++qc]=j;
	}
	for(int i=n/k+1;i<=n;i++)if(!vis[i])q[k][++qc]=i;
	return cnt;
} 
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int test2=test(2);
		int test3=test(3);
		if(test2>test3)
		{
			cout<<2<<'\n';
			for(int i=1;i<=n;i++)cout<<q[2][i]<<' ';
			cout<<'\n';
		}
		else
		{
			cout<<3<<'\n';
			for(int i=1;i<=n;i++)cout<<q[3][i]<<' ';
			cout<<'\n';
		}
	}
	return 0;
}

