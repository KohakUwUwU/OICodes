//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,k;
int p[N][64];
signed main()
{
	freopen("basketball.in","r",stdin);
	freopen("basketball.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>p[i][0];
	for(int j=1;j<=63;j++)
	{
		for(int i=1;i<=n;i++)p[i][j]=p[p[i][j-1]][j-1];
	}
	int cur=1;
	for(int i=63;i>=0;i--)
	{
		int kk=(1ll<<i);
		if(kk&k)cur=p[cur][i];
	}
	cout<<cur;
	return 0;
}

