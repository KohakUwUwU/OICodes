#include<iostream>
using namespace std;
int a[10005],n,cur=1,mx=-0x3f3f3f3f;
int main()
{
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==a[i-1]+1)cur++;
		else mx=max(cur,mx),cur=1;
	}
	cout<<mx;
}
