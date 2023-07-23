#include<iostream>
using namespace std;
int a[10001];
int main()
{
	int n;
	cin>>n;
	cin>>a[1];
	cout<<"0 ";
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		int cnt=0;
		for(int j=1;j<i;j++)if(a[j]<a[i])++cnt;
		cout<<cnt<<" ";
	}
}
