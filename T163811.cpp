#include<iostream>
using namespace std;
int n,w,a[30005];
int main()
{
	int mx=-1;
	cin>>n>>w;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((a[j]-a[i])%(j-i)!=0)continue;
			int ch=(a[j]-a[i])/(j-1);
			int cnt=3;
			for(int k=2;k<=n;k++)if(a[i]==(k-i)*ch)cnt++;
			mx=max(cnt,mx);
		}
	}
	cout<<n-mx;
}
