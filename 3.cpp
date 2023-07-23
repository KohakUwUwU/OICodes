#include<iostream>
using namespace std;
int main()
{
	int n,m,a[101]={},b[101]={};
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)a[i]=i;
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[2*j-1]=a[n+j];
			b[2*j]=a[j];
		}
		for(int j=1;j<=2*n;j++)a[j]=b[j];
	}
	for(int i=1;i<=2*n;i++)cout<<a[i]<<" ";
}
