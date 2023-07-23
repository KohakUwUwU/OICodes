#include<stdio.h>
#include<math.h>
int a,b,c,delta;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	delta=b*b-4*a*c;
	if(delta<0)
	{
		printf("no answer");
	}
	else if(delta==0)printf("%lf",-b*1.0/(2.0*double(a)));
	else printf("%.4lf %.4lf",(-b*1.0-sqrt(delta))/(2.0*double(a)),(-b*1.0+sqrt(delta))/(2.0*double(a)));
	return 0;
}
