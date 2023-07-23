#include<stdio.h>
int m,n,ans;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=(m>n?m:n);i++)if(m%i==0&&n%i==0)ans=i;
	printf("%d",ans);
}
