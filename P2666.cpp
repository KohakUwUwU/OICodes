#include<iostream>
using namespace std;
int n,ans=0;
int main()
{
	cin>>n;
	for(int i=0;i<=100;++i)for(int j=0;j<=100;++j)for(int k=0;k<=100;++k)for(int m=0;m<=100;++m)if(i*i+j*j+k*k+m*m==n)ans++;
	cout<<ans;
	return 0;
}
