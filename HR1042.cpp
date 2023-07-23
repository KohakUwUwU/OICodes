#include<stdio.h>
double a[3];
int main()
{
	scanf("%lf%lf%lf",&a[0],&a[1],&a[2]);
	for(int i=0;i<=2;i++)
	for(int j=i+1;j<=2;j++)
	{
		if(a[i]>a[j])
		{
			int tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
	}
	printf("%.2lf %.2lf %.2lf",a[0],a[1],a[2]);
}
