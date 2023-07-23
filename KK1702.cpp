#include <bits/stdc++.h>
#define ll long long
const int ykn=998244353;
const int bbs=102;
int n,m,a[105][2005],f[105][105]={0},g[105][205][2],sum[105]={0},ans[105]={0};
//RAISE A SUILEN
//By CHUCHU
int main(){
	int mnt=1;
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){for(int j=1;j<=m;++j){scanf("%d",&a[i][j]);sum[i]=(sum[i]+a[i][j])%ykn;}mnt=(ll)mnt*(sum[i]+1)%ykn;}
	for(int p=1;p<=m;++p){memset(g,0,sizeof(g));g[0][1+bbs][0]=1;for(int i=1;i<=n;++i){
		for(int j=-i;j<=i;++j){g[i][j+bbs][0]=(g[i-1][j+bbs][0]+(ll)g[i-1][j+bbs-1][1]*(sum[i]-a[i][p]+ykn)%ykn+(ll)g[i-1][j+bbs][1]*a[i][p]%ykn)%ykn;g[i][j+bbs][1]=(g[i-1][j+bbs][1]+
				(ll)g[i-1][j+bbs][0]*(sum[i]-a[i][p]+ykn)%ykn+(ll)g[i-1][j+bbs+1][0]*a[i][p]%ykn)%ykn;}}
		for(int j=-n;j<=0;++j)mnt=(mnt-(g[n][j+bbs][0]+g[n][j+bbs][1])%ykn+ykn)%ykn;
	}
	printf("%d",(mnt-1+ykn)%ykn);
	return 0-0;
}
