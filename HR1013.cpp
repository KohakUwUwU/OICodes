#include<stdio.h>
int a[11],ans=-1;
int main()
{
	for(int i=1;i<=10;i++)scanf("%d",&a[i]),ans=a[i]>ans?a[i]:ans;
	printf("%d",ans);
}
