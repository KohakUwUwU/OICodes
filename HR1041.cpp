#include<stdio.h>
double a,b;
int main()
{
	scanf("%lf%lf",&a,&b);
	printf("%.2lf %.2lf",a<b?a:b,a>b?a:b);
}
