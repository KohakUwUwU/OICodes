#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	double sum=0,ini=100;
	for(int i=1;i<=n;i++)
	{
		sum+=ini;
		ini/=2;
	}
	printf("length=%.4lf\nhigh=%.4lf",sum,ini);
}
