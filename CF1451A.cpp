#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int tmp;
		cin>>tmp;
		if(tmp==1)cout<<0<<endl;
		else if(tmp==2)cout<<1<<endl;
		else if(tmp==3)cout<<2<<endl;
		else if(tmp%2==0)cout<<2<<endl;
		else cout<<3<<endl;
	}
}
