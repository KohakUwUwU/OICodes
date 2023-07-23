#include<iostream>
using namespace std;
string a;
int main()
{
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='A'&&a[i]<='Z')cout<<char(26-(a[i]-'A')+'A'-1);
		else if(a[i]>='a'&&a[i]<='z')cout<<char(26-(a[i]-'a')+'a'-1);
		else cout<<a[i];
	}
}
