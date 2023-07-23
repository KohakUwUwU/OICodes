#include<iostream>
using namespace std;
int a[2000005],m,n;
int main()
{
	int tmp=0;
	cin>>m>>n;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int j=1;j<=n;j++)cin>>tmp,cout<<a[tmp]<<endl;
}
