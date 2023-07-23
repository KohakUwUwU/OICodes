#include<iostream>
using namespace std;
int main()
{
	int n,cnt5=0,cnt0=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		if(tmp==5)cnt5++;
		else cnt0++;
	}
	if(cnt0==0)
	{
		cout<<-1;
		return 0;
	}
	if((cnt5/9)*9==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=(cnt5/9)*9;i++)cout<<5;
	for(int i=1;i<=cnt0;i++)cout<<0;
}
