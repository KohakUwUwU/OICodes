//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
const int INF=114514114514;
int n,cnt,a[N];
int d[2001][2001],ma[2001][2001];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i])i--,n--;
		else cnt++;
	}
	if(cnt>=128)
	{
		cout<<3;
		return 0;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=ma[i][j]=INF;
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]&a[j])d[i][j]=d[j][i]=ma[i][j]=ma[j][i]=1;
		}
	}
	int ans=INF;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		{
			if(i==k)continue;
			for(int j=i+1;j<k;j++)
			{
				ans=min(ans,d[i][j]+ma[i][k]+ma[k][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	if(ans==INF)cout<<-1;
	else cout<<ans;
	return 0;
}

