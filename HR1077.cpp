#include<stdio.h>
#include<math.h>
int main()
{
	int a,n,ans=0;
	scanf("%d%d",&a,&n);
	for(int i=1;i<=n;i++)
	{
		ans+=pow(10,i-1)*(n-i+1)*a;
	}
	printf("%d",ans);
}
