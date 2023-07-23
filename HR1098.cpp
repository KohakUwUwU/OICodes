#include<iostream>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int len=max(a.length(),b.length());
	for(int i=0;i<len;i++)
	{
		if(a[i]!=b[i])
		{
			cout<<a[i]-b[i];
			return 0;
		}
	}
	cout<<0;
}
