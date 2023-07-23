#include<iostream>
using namespace std;
int n,arr[100005],cnt,state=0;
int main()
{
	cin>>n;
	cin>>arr[1];
	for(int i=2;i<=n;i++)
	{
		cin>>arr[i];
		if(arr[i]<arr[i-1])state=1;
		if(arr[i]>arr[i-1]&&state==1)state=0,cnt++;
	}
	cout<<cnt;
}
