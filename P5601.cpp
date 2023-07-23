#include<bits/stdc++.h>
using namespace std;
map<string,string>st;
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
signed main()
{
	int n,q;
	n=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		string str1,str2;
		cin>>str1>>str2;
		st[str1]=str2;
	}
	for(int i=1;i<=q;++i)
	{
		string s1,s2,s3,s4,s5;
		cin>>s1>>s2>>s3>>s4>>s5;
		if(st[s1]==s2)cout<<"A\n";
		if(st[s1]==s3)cout<<"B\n";
		if(st[s1]==s4)cout<<"C\n";
		if(st[s1]==s5)cout<<"D\n";
	}
    return 0;
}

