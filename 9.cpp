#include<iostream>
using namespace std;
int a[1>>10];
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=2;i*i<=n;i++)if(a[i]==0)for(int j=i*i;j<=n;j+=i)a[j]=1;
	for(int i=2;i<=n;i++)if(a[i]==0)sum++;
	cout<<sum;
	return 0;
}
