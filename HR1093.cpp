#include<stdio.h>
int main()
{
	int a[11];
	for(int i=1;i<=10;i++)scanf("%d",&a[i]);
	for(int i=10;i>=1;i--)printf("%d\n",a[i]);
}
