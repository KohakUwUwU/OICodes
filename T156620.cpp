#include<iostream>
using namespace std;
int main()
{
	short n;
	cin>>n;
	cout<<"log[log[5-1]{1+1}]{log[4]{";
	for(int i=1;i<=n;i++)cout<<"sqrt{";
	cout<<4;
	for(int i=1;i<=n+2;i++)cout<<'}';
	cout<<'\n';
}

