#include<stdio.h>
#include<math.h>
double a,b,c,p;
int main()
{
	scanf("%lf%lf%lf",&a,&b,&c);
	p=(a+b+c)/2.0;
	printf("area=%lf",sqrt(p*(p-a)*(p-b)*(p-c)));
}
