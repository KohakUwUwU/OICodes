#include<iostream>
using namespace std;
int dateb[15]={0,31,30,31,30,31,30,31,31,30,31,30,31};
bool hw(int k)
{
	int m=0,ori=k;
	for(int i=1;i<=8;i++)
	{
		m*=10;
		m+=k%10;
		k/=10;
	}
	if(ori==m)return true;
	else return false;
}
bool date(int k)
{
	int m=k/10000;
	k%=10000;
	if(k/100==2)
	{
		if((m%4==0&&m%100!=0||m%400==0)&&k%100<=29||(!(m%4==0&&m%100!=0||m%400==0))&&k%100<=28)return true;
		else return false;
	}
	if(dateb[k/100]>=k%100)return true;
	else return false;
}
int main()
{
	int a;
	cin>>a;
	if(date(a))cout<<"yes";
	else cout<<"no";
}
