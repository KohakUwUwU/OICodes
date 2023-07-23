//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+5;
int n,m,a[N][N],ans[N];
signed main()
{
	freopen("kingdom.in","r",stdin);
	freopen("kingdom.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
	{
		cin>>a[i][j];
		ans[j]+=a[i][j];
	}
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		int tmp,temp;
		cin>>tmp;
		if(ans[i]>m-ans[i])temp=1;
		else temp=0;
		if(tmp==temp)ret++;
	}
	cout<<ret;
	return 0;
}

