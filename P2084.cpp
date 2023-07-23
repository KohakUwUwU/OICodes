#include<iostream>
using namespace std;
int n;
string m;
int main()
{
	cin>>n>>m;
	m[0]-='0';
	if(m[0]!=0)
	{
		cout<<int(m[0])<<"*"<<n<<"^"<<m.length()-1;
	}
	for(int i=1;i<m.length();i++)
	{
		m[i]-='0';
		if(m[i]!=0)
		{
			cout<<"+"<<int(m[i])<<"*"<<n<<"^"<<m.length()-1-i;
		}
	}
}
