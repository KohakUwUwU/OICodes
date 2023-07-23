//And in that light, I find deliverance.
#include<stdio.h>

const int N=1e5+1;
int n,d[100001],ans;
signed main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;++i)scanf("%d",&d[i]);
	for(register int i=1;i<=n;i++)if(d[i]>d[i-1])ans+=(d[i]-d[i-1]);
	printf("%d",ans);
	return 0;
}
