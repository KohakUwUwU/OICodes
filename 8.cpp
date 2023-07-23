#include<iostream>
using namespace std;
int tong[129];
int main()
{
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++)tong[a[i]]++;
	int mi=100;
	char ch;
	for(int i=0;i<128;i++)
	{
		if(tong[i]<mi&&tong[i])mi=tong[i];
	}
	for(int i=0;i<a.length();i++)
	{
		if(tong[a[i]]>mi)cout<<a[i];
	}
}
