#include<iostream>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	int b,sum=0;
	cin>>b;
	while(b)
	{
		sum+=a[b%10];
		b/=10;
	}
	cout<<sum;
}
