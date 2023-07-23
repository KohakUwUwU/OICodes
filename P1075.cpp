#include<stdio.h>
int main()
{
	int n,i=2;
	scanf("%d",&n);
	for(;;i++)if(n%i==0){
		printf("%d",n/i);
		return 0;
	}
}
