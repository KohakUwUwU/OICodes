#include<stdio.h>
unsigned long long cnt,in,sum,inlast=-1;
int main()
{
	while(scanf("%llu",&in)!=EOF)
	{
//		if(in==inlast)break;
//		else inlast=in;
		cnt++;
		sum+=in;
	}
	printf("%llu",sum<<(cnt-1));
}
