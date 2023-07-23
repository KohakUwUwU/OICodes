#include<iostream>
using namespace std;
int main()
{
	int ans=0;
	for(int i=1;i<=101;i++)
	{
		ans+=i;if(i==100)break;
	}
	printf("%d",ans);
}
