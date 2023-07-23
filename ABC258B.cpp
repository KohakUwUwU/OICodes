//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=20;
int n,a[N][N];
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		for(int j=0;j<n;j++)
		{
			a[i][j]=str[j]-'0';
		}
	}
	int ans=0;
	int mul=1;
	for(int i=1;i<n;i++)mul*=10;
	for(int i=0;i<n;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)num=num*10+a[j%n][(i+j)%n];
		for(int j=0;j<n;j++)
		{
			ans=max(ans,num);
			num=num/10+mul*(num%10);
		}
	}
	for(int i=0;i<n;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)num=num*10+a[n-j%n-1][n-(i+j)%n-1];
		for(int j=0;j<n;j++)
		{
			ans=max(ans,num);
			num=num/10+mul*(num%10);
		}
	}
	for(int i=0;i<n;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)num=num*10+a[n-j%n-1][(i+j)%n];
		for(int j=0;j<n;j++)
		{
			ans=max(ans,num);
			num=num/10+mul*(num%10);
		}
	}
	for(int i=0;i<n;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)num=num*10+a[j%n][n-(i+j)%n-1];
		for(int j=0;j<n;j++)
		{
			ans=max(ans,num);
			num=num/10+mul*(num%10);
		}
	}
	for(int i=0;i<n;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)num=num*10+a[i][j];
		for(int j=0;j<n;j++)
		{
			ans=max(ans,num);
			num=num/10+mul*(num%10);
		}
	}
	for(int i=0;i<n;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)num=num*10+a[i][n-j-1];
		for(int j=0;j<n;j++)
		{
			ans=max(ans,num);
			num=num/10+mul*(num%10);
		}
	}
	for(int i=0;i<n;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)num=num*10+a[j][i];
		for(int j=0;j<n;j++)
		{
			ans=max(ans,num);
			num=num/10+mul*(num%10);
		}
	}
	for(int i=0;i<n;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)num=num*10+a[n-j-1][i];
		for(int j=0;j<n;j++)
		{
			ans=max(ans,num);
			num=num/10+mul*(num%10);
		}
	}
	cout<<ans;
	return 0;
}

