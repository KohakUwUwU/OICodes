#include<stdio.h>
double ans;
int main()
{
	for(double i=1;i<=100;i+=2)ans+=1.0/i;
	for(double i=2;i<=100;i+=2)ans-=1.0/i;
	printf("%.8lf",ans);
}
