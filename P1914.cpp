#include<iostream>
using namespace std;
int main()
{
	int n;
	string a;
	cin>>n>>a;
	for(int i=0;i<a.length();i++)cout<<char((a[i]-'a'+n)%26+'a');
}
