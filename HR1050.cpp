#include<stdio.h>
double a;
inline double j()
{
	if(a<1)return a;
	else if(a<10)return 2.0*a-1.0;
	else return 3.0*a-11.0;
}
int main()
{
	scanf("%lf",&a);
	printf("y=%.2lf",j());
}
