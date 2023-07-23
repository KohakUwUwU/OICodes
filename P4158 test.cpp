#include"cstdio"
#include"cstring"
#include"iostream"
#include"algorithm"
using namespace std;

const int MAXN=55;
const int MAXT=2505;

int n,m,T;
int cnt[MAXN][2];
int dp[MAXN][MAXN][2];
int f[MAXT];

int main()
{
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;++i){
		memset(cnt,0,sizeof(cnt));bool b;
		for(int j=1;j<=m;++j){
			scanf("%1d",&b);
			cnt[j][b]=cnt[j-1][b]+1;
			cnt[j][b^1]=cnt[j-1][b^1];
		}for(int j=1;j<=m;++j){
			for(int k=0;k<j;++k){
				for(int l=1;l<=j;++l){
					for(int o=0;o<2;++o){
						dp[j][l][o]=max(dp[k][l][o],dp[k][l-1][o^1])+cnt[j][o]-cnt[k][o];
					}
				}
			}
		}for(int j=T;j;--j){
			for(int k=1;k<=min(m,j);++k){
				f[j]=max(f[j],f[j-k]+max(dp[m][k][0],dp[m][k][1]));
			}
		}
	}printf("%d\n",f[T]);
	return 0;
}
