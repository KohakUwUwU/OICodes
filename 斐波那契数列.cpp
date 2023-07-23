#include<iostream>
using namespace std;
int n,f[1001]={0,1,1};
int main()
{
	cin>>n;
	if(n<=2)
	{
		cout<<1;
		return 0;
	}
	for(int i=3;i<=n;i++)f[i]=f[i-1]+f[i-2];
	cout<<f[n];
}
