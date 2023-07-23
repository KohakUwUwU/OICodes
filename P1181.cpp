#include<iostream>
#define N 100005
using namespace std;
int n,m,cur,cnt=1;
int arr[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		cur+=arr[i];
		if(cur>m&&i!=n)
		{
			cnt++;
			cur=arr[i];
		}
	}
	if(cnt!=3)cout<<cnt;
	else cout<<4;
}
