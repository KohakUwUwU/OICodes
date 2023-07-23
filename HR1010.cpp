#include<stdio.h>
short n;
int main()
{
	scanf("%d",&n);
	if(n%4==0&&n%100!=0||n%400==0)printf("leap year");
	else printf("not leap year");
}
