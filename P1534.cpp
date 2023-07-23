#include<iostream>
using namespace std;
int n,unhappy,sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		register int a,b;
		cin>>a>>b;
		unhappy=unhappy+a+b-8;
		sum+=unhappy;
	}
	cout<<sum;
}
