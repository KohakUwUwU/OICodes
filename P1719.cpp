//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=125;
int n,ans=-114514114514,ma[N][N],pre[N][N];
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lld",&ma[i][j]);
	for(int i=1;i<=n;i++)pre[i][1]=pre[i-1][1]+ma[i][1],pre[1][i]=pre[1][i-1]+ma[1][i];
	for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+ma[i][j];
	for(int x1=1;x1<=n;x1++)for(int y1=1;y1<=n;y1++)for(int x2=x1;x2<=n;x2++)for(int y2=y1;y2<=n;y2++)
		ans=max(ans,pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]);
	printf("%lld",ans);
	return 0;
}

