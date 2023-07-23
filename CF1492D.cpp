#include<iostream>
using namespace std;
int a,b,k;
int main()
{
	cin>>a>>b>>k;
	if(k==0)
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=b;i++)
		{
			cout<<1;
		}
		for(int i=1;i<=a;i++)
		{
			cout<<0;
		}
		cout<<endl;
		for(int i=1;i<=b;i++)
		{
			cout<<1;
		}
		for(int i=1;i<=a;i++)
		{
			cout<<0;
		}
		return 0;
	}
	if(a+b-1<=k||b<=1||a<1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=b;i++)
		{
			cout<<1;
		}
		for(int i=1;i<=a;i++)
		{
			cout<<0;
		}
		cout<<endl;
		if(a>=k)
		{
			for(int i=1;i<b;i++)
			{
				cout<<1;
			}
			for(int i=1;i<=k;i++)
			{
				cout<<0;
			}
			cout<<1;
			for(int i=k+1;i<=a;i++)
			{
				cout<<0;
			}
			cout<<endl;
		}
		else
		{
			int t=k-a;
			for(int i=1;i<=b-t-1;i++)
			{
				cout<<1;
			}
			cout<<0;
			for(int i=b-t+1;i<=b;i++)
			{
				cout<<1;
			}
			for(int i=1;i<a;i++)
			{
				cout<<0;
			}
			puts("1");
		}	
	}
	return 0;
}
