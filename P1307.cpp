#include<iostream>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int start=0,end=a.length()-1;
	if(a[0]=='-')start++,cout<<"-";
	while(a[end]=='0')end--;
	for(int i=end;i>=start;i--)
	{
		cout<<a[i];
	}
}
