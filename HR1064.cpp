#include<stdio.h>
int main()
{
	int n,ans;
	for(int i=1;i<=100;i++)
	{
		ans+=i;
		if(ans>1000)
		{
			ans=i;
			break;
		}
	}
	printf("%d",ans);
}
