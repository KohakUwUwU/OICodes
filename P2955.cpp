#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		if((str[str.length()-1]-'0')%2)cout<<"odd"<<'\n';
		else cout<<"even"<<'\n';
	}
}
