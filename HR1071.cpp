#include<iostream>
using namespace std;
string a;
int main()
{
	getline(cin,a);
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='a'&&a[i]<='z')a[i]=((a[i]-'a')+4)%26+'a';
		if(a[i]>='A'&&a[i]<='Z')a[i]=((a[i]-'A')+4)%26+'A';
	}
	cout<<a<<endl;
}
