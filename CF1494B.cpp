#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,u,r,d,l,ok=0;
		cin>>n>>u>>r>>d>>l;
		for(int i=0;i<=1;i++)for(int j=0;j<=1;j++)for(int k=0;k<=1;k++)for(int m=0;m<=1;m++)if(u-i-j>=0&&u-i-j<=n-2&&r-j-k>=0&&r-j-k<=n-2&&d-k-m>=0&&d-k-m<=n-2&&l-m-i>=0&&l-m-i<=n-2)
		{
			cout<<"YES\n";ok=1;
			goto flag;
		}
		flag:;
		if(!ok)cout<<"NO\n";
	}
}
