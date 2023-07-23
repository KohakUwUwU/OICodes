#include<stdio.h>
int c;
int main()
{
	scanf("%d",&c);
	if(c>0)puts("1");
	else if(c==0)puts("0");
	else puts("-1");
}
