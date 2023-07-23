#include<iostream>
using namespace std;
int a[15],sum=0;
int main()
{
	for(int i=1;i<=10;i++)cin>>a[i],a[i]-=30;
	cin>>a[0];
	for(int i=1;i<=10;i++)if(a[i]<=a[0])sum++;
	cout<<sum;
}
