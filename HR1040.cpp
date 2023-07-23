#include<stdio.h>
int a,b,c,delta;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	delta=b*b-4*a*c;
	if(delta<0)printf("No real roots!");
}
