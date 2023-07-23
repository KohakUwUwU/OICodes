#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	while(1)
	{
		int sum=0,time,floor=0,input=0;
		cin>>time;
		if(time==0)return 0;
		sum+=time*5;
		for(int i=0;i<time;i++)
		{
			cin>>input;
			sum+=abs(floor-input)*3;
			floor=input;
		}
		cout<<sum<<endl;
	}
}
