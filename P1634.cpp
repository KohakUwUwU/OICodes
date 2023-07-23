#include<iostream>
using namespace std;
int main()
{
	unsigned long long sum=0;
	unsigned long long m,n;
	cin>>m>>n;
	sum=1;
	while(n--)
	{
		sum=sum+sum*m;
	}
	cout<<sum;
}
