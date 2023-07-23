#include<iostream>
using namespace std;
long long a[1000001],n;
long long cnt=1,mx=0;
int main()
{
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]<a[i])cnt++;
		else mx=max(mx,cnt),cnt=1;
	}
	mx=max(mx,cnt);
	cout<<mx;
}
