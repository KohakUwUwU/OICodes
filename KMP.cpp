#include<iostream>
using namespace std;
string s,t;//Ö÷´® Ä£Ê½´® 
int fail[10001];
inline void getFail()
{
	int j=0;
	for(int i=0;i<t.length();i++)
	{
		while(j>0&&t[j+1]!=t[i+1])j=fail[j];
		if(t[j+1]==t[i+1])j++;
		fail[i+1]=j;
	}
}
inline void KMP()
{
	int j=(s[0]==t[0]?1:0);
	for(int i=0;i<s.length();i++)
	{
		while(j>0&&t[j+1]!=s[i+1])j=fail[j];
		if(t[j+1]==s[i+1])j++;
		if(j==t.length())cout<<i-t.length()+2,j=fail[j];
	}
}
int main()
{
	cin>>s>>t;
	getFail();
	KMP();
}
