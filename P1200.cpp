#include<iostream>
using namespace std;
string a,b;
int numa=1,numb=1;
int main()
{
	cin>>a>>b;
	for(int i=0;i<a.length();i++)
	{
		numa*=a[i]-'A'+1;
	}
	for(int i=0;i<b.length();i++)
	{
		numb*=b[i]-'A'+1;
	}
	if(numa%47==numb%47)cout<<"GO";
	else cout<<"STAY";
}
