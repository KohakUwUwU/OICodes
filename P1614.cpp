#include<iostream>
using namespace std;
int n,m,a[3005],b[3005],ans=2e9;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	   cin>>a[i];
	for(int i=m;i<=n;i++)
	   {
	   	for(int j=i-m+1;j<=i;j++)
	   	   b[i]+=a[j];
	}
	for(int i=m;i<=n;i++)
	   if(ans>b[i])
	     ans=b[i];//求最大值。 
	cout<<ans;//输出。 
	return 0;
}
