#include<iostream>
using namespace std;
int n,mx=-1,mn=10000;
int main()
{
	cin>>n;
	for(int i=1,tmp;i<=n;i++)cin>>tmp,mx=max(mx,tmp),mn=min(mn,tmp);
	cout<<mx-mn;
}
