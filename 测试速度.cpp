#include<iostream>
using namespace std;
int main()
{
	long long a,b,cnt=0;
	a=1e18,b=2e18;
	for(long long i=1;i<=a;i++)++cnt;
	for(long long j=1;j<=b;j++)++cnt;
	cout<<cnt;
}
