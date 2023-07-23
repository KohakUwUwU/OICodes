#include<bits/stdc++.h>
long long m,n,i,j,map[1001][1001],minn=0x3f3f3f3f3f;
int main()
{
	scanf("%lld%lld",&m,&n);
	for(;i<n;i++)for(j=1;j<=m;j++)scanf("%lld",&map[i][j]);
	for(i=1;i<m;i++)for(j=0;j<n;j++)map[j][i]+=map[j][i-1]<map[(j-1+n)%n][i-1]?map[j][i-1]:map[(j-1+n)%n][i-1];
	for(i=0;i<n;i++)minn=std::min(minn,map[i][m]+std::min(map[i][m-1],map[(i-1+n)%n][m-1]));
	printf("%lld",minn);
}
