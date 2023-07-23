#include<iostream>
using namespace std;
int n;
string str;
int bin[101];
int main()
{
	int cnt=0;
	cin>>n>>str;
	for(int i=0;i<n-1;i++)if(str[i]=='V'&&str[i+1]=='K')
	{
		cnt++;
		bin[i]=bin[i+1]=1;
	}
	for(int i=0;i<n-1;i++)if(((str[i]=='K'&&str[i+1]=='K')||(str[i]=='V'&&str[i+1]=='V'))&&!bin[i]&&!bin[i+1])
	{
		cnt++;
		break;
	}
	cout<<cnt;
}
