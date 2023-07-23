#include<stdio.h>
short i,j,m,map[1001][1001];
int f[1001][1001],maxx=0,tmp;
int main()
{
	scanf("%d",&m);
	for(i=1;i<=m-1;i++)for(j=1;j<=i;j++)scanf("%d",&map[i][j]),f[i][j]=map[i][j]+(f[i-1][j]>f[i-1][j-1]?f[i-1][j]:f[i-1][j-1]);
	for(i=1;i<=m;i++)scanf("%d",&map[m][i]),tmp=map[m][i]+(f[m-1][i]>f[m-1][i-1]?f[m-1][i]:f[m-1][i-1]),maxx=maxx>tmp?maxx:tmp;
	printf("%d",maxx);
}
