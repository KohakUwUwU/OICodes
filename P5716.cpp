#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(m!=2)
	{
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)cout<<31;
		else cout<<30;
	}
	else
	{
		if(n%4==0&&n%100!=0||n%400==0)cout<<29;
		else cout<<28;
	}
}
