#include<iostream>
#include<cmath>
#define U unsigned long long
using namespace std;
int t,b=97;
string str1,str2;
U hash[10001],bpow[10001]={1};
int main()
{
	cin>>t;
	for(int i=1;i<=10000;i++)bpow[i]=bpow[i-1]*b;
	while(t--)
	{
		cin>>str1>>str2;
		if(str1==str2)
		{
			cout<<1<<endl;
			continue;
		}
		U cnt=0,has=0;
		for(int i=0;i<str1.length();i++)has=has*b+str1[i]-'A';
		cout<<has<<endl;
		for(int i=1;i<=str2.length();i++)
		{
			hash[i]=hash[i-1]*b+str2[i-1]-'A';
			cout<<hash[i]<<endl;
			if(i>=str1.length())if(has==hash[i]-hash[i-str1.length()]*pow(b,str1.length()))cnt++;
		}
		cout<<cnt;
	}
}
