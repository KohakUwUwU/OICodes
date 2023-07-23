#include<iostream>
#include<cmath>
using namespace std;
int n,a[10001];
bool judge[10001];
int main()
{
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		judge[abs(a[i]-a[i-1])]=true;
	}
	for(int i=1;i<n;i++)
	{
		if(judge[i]==0)
		{
			cout<<"Not jolly";
			return 0;
		}
	}
	cout<<"Jolly";
}
