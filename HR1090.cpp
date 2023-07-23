#include<stdio.h>
int a[11];
int main()
{
	for(int i=1;i<=10;i++)scanf("%d",&a[i]);
	for(int i=1;i<=10;i++)
	{
		for(int j=i+1;j<=10;j++)
		{
			if(a[i]>a[j])
			{
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	for(int i=1;i<=10;i++)printf("%d\n",a[i]);
}
