#include<stdio.h>
int main()
{
	int i=100,ans=0;
	do{
		ans+=i;i--;
	}while(i>0);
	printf("%d",ans);
}
