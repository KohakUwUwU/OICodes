#include<iostream>
#include<algorithm>
using namespace std;
long long a[100001];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	long long mul=1;
	for(int i=1;i<=n;i++)
	{
		mul*=(a[i]-i+1);
		mul%=1000000007;
	}
	cout<<mul;
}
