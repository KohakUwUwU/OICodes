#include<iostream>
using namespace std;
int a,b;
int dateb[15]={0,31,30,31,30,31,30,31,31,30,31,30,31};
inline bool hw(int k)
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
inline bool date(int k)
{
	int m=k/10000;
	k%=10000;
	if(k/100==0||k/100>12||k%100==0)return false;
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
	int cnt=0;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		if(hw(i)&&date(i))cnt++;
	}
	cout<<cnt;
}
