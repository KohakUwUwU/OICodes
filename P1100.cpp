#include<iostream>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long a=n>>16;
	long long b=(n-(a<<16))<<16;
	cout<<a+b;
}
