#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,g;
int w[501][501],v[501][501],f[101][50001];
signed main()
{
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	cin>>c>>n>>g;
	for(int i=1;i<=n;i++)
	{
		int ww,vv,cc;
		cin>>ww>>vv>>cc;
		w[cc][++w[cc][0]]=ww;
		v[cc][++v[cc][0]]=vv;
	}
	for(int i=1;i<=c;i++)f[0][i]=-0x3f3f3f3f;
	for(int i=1;i<=g;i++)
	{
		for(int j=0;j<=c;j++)
		{
			f[i][j]=-0x3f3f3f3f;
			for(int k=1;k<=w[i][0];k++)
			{
				if(j>=w[i][k]&&f[i-1][j-w[i][k]]>=0)f[i][j]=max(f[i][j],f[i-1][j-w[i][k]]+v[i][k]);
			}
		}
	} 
//	for(int i=1;i<=g;i++)
//	{
//		for(int j=0;j<=c;j++)f[i][j]==-0x3f3f3f3f?cout<<"-INF"<<' ':cout<<f[i][j]<<' ';
//		cout<<endl;
//	}
	int mx=-0x3f3f3f3f;
	for(int i=0;i<=c;i++)mx=max(mx,f[g][i]);
	cout<<(mx==-0x3f3f3f3f?-1:mx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
