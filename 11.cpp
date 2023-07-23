#include<iostream>
using namespace std;
int main()
{
	int a,b,time=0;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		int tmp=i;
		while(tmp)
		{
			if(tmp%10==2)time++;
			tmp/=10;
		}
	}
	cout<<time;
}
