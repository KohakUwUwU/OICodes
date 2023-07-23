#include<iostream>
int main()
{
	int cnt=0;
	for(int i=100;i<=200;i++)
	{
		if(i%3!=0&&i!=137)
		{
			printf("%d ",i),cnt++;
		if(cnt%5==0)printf("\n");
		}
	}
}
