#include<iostream>
using namespace std;
int a[100001];
int main()
{
	int n;
	cin>>n;
	cin>>a[1];
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<n;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])cnt++;
		if(a[i]<a[i-1]&&a[i]<a[i+1])cnt++;
	}
	cout<<cnt;
}
