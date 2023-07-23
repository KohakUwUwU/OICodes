#include<iostream>
#include<iomanip>
using namespace std;
int n,arr[10001],cnt,sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(arr[i]<60)cnt++;
		sum+=arr[i];
	}
	cout<<fixed<<setprecision(1)<<sum*1.0/double(n)<<endl;
	cout<<cnt;
}
