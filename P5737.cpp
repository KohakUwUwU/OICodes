#include<iostream>
using namespace std;
int m,n,ans,kkksc03[1001];
int main()
{
	cin>>m>>n;
	for(int i=m;i<=n;i++)
	{
		if(i%4==0&&i%100!=0||i%400==0)
		{
			ans++;
			kkksc03[++kkksc03[0]]=i;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=kkksc03[0];i++)cout<<kkksc03[i]<<" ";
}
