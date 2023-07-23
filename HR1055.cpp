#include<stdio.h>
int main()
{
	int a,tmp=0,arr[6];
	scanf("%d",&a);
	while(a)
	{
		arr[++tmp]=a%10;
		a/=10;
	}
	for(int i=1;i<=tmp;i++)printf("%d ",arr[i]);
}
