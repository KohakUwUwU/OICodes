#include<iostream>
using namespace std;
int n,a[10001],cnt;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(1)
	{
		int tmp=0;
		for(int i=1;i<n;i++)if(a[i]>a[i+1])swap(a[i],a[i+1]),cnt++,tmp=1;
		if(tmp==0)
		{
			cout<<cnt;
			return 0;
		}
	}
}
