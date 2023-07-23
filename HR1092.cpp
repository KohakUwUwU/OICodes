#include<stdio.h>
int a[11],tmp;
int main()
{
	for(int i=1;i<=9;i++)scanf("%d",&a[i]);
	scanf("%d",&tmp);
	int i=0;
	while(a[++i]<tmp);
	for(int j=9;j>=i;j--)a[j+1]=a[j];
	a[i]=tmp;
	for(i=1;i<=10;i++)printf("%d\n",a[i]);
}
