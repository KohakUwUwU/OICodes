#include<iostream>
using namespace std;
string str,ar[10001];
int n,sum;
bool cccc(int f)
{
	for(int i=0;i<str.length();i++)if(str[i]!=ar[f][ar[i].length()-1-i])return 0;
	else return 1;
}
int main()
{
	cin>>str;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		if(cccc(i))sum++;
	}
	cout<<sum;
}
