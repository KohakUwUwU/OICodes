#include<iostream>
using namespace std;
int main()
{
	string a;
	int ans;
	getline(cin,a);
	for(int i=0;i<a.length();i++)
	{
		if(a[i]==' ')ans++;
	}
	cout<<ans+1;
}
