#include<iostream>
using namespace std;
int main()
{
	int n,v,m,a,sum=0;
	cin>>n>>v>>m>>a;
	for(int i=1;i<=n;i++)
	{
		sum+=v;
		if(i%m==0)v+=a;
	}
	cout<<sum;
}
