#include<iostream>
using namespace std;
int kkksc03[10001],n;
void prime()
{
	for(int i=2;i<=n;i++)
	{
		if(kkksc03[i]==0)
		{
			for(int j=i*i;j<=n;j+=i)
			{
				kkksc03[j]=1;
			}
		}
	}
}
int main()
{
	cin>>n;
	prime();
	for(int i=4;i<=n;i+=2)
	{
		for(int j=2;j<=i;j++)
		{
			if(kkksc03[j]==0&&kkksc03[i-j]==0)
			{
				cout<<i<<"="<<j<<"+"<<i-j<<endl;
				break;
			}
		}
	}
}
