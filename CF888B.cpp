#include<iostream>
using namespace std;
int main()
{
	int n,a[4]={};
	cin>>n;
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='U')a[0]++;
		if(str[i]=='D')a[1]++;
		if(str[i]=='L')a[2]++;
		if(str[i]=='R')a[3]++;
	}
	cout<<min(a[0],a[1])*2+min(a[2],a[3])*2;
}
