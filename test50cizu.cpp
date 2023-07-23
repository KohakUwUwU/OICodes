#include<iostream>
using namespace std;
int arr[51];
int main()
{
	for(int i=1;i<=50;i++)cin>>arr[i];
	for(int i=1;i<=50;i++)
	{
		cout<<i<<" "<<arr[i]<<endl;
	}
}
