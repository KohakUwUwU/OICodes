#include<iostream>
using namespace std;
int main()
{
	int n,cnt=0,np;
	cin>>n;np=n;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			++cnt;
			if(cnt/10==0)cout<<0;
			cout<<cnt;
		}
		cout<<'\n';
	}
}
