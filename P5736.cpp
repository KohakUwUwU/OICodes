#include<iostream>
using namespace std;
int n,in;
bool prime(int kkksc03)
{
	if(kkksc03==1||kkksc03==0)return false;
	for(int i=2;i*i<=kkksc03;i++)if(kkksc03%i==0)return false;
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>in;
		if(prime(in))cout<<in<<" ";
	}
}
