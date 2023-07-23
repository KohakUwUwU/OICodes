#include<stdio.h>
#include<math.h>
int a,b,c,delta;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	delta=b*b-4*a*c;
	printf("r1=%7.2lf\nr2=%7.2lf",(-b*1.0+sqrt(delta))/(2.0*double(a)),(-b*1.0-sqrt(delta))/(2.0*double(a)));
	return 0;
}
