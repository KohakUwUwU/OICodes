#include<bits/stdc++.h>
using namespace std;
string s1,s2;
unsigned long long HASH=11451411,hash1[15],hash2[1000001],ha[1000001],cnt;
int first=-1;
int main()
{
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s1.length();i++)if(s1[i]>='A'&&s1[i]<='Z')s1[i]=s1[i]-'A'+'a';
	for(int i=0;i<s2.length();i++)if(s2[i]>='A'&&s2[i]<='Z')s2[i]=s2[i]-'A'+'a';
	int len=max(s1.length(),s2.length())+1;
	ha[0]=1;hash1[0]=s1[0];hash2[0]=s2[0];
	for(int i=1;i<=len;i++)ha[i]=ha[i-1]*HASH;
	for(int i=1;i<s1.length();i++)hash1[i]=hash1[i-1]+s1[i]*ha[i];
	for(int i=1;i<s2.length();i++)
	{
		hash2[i]=hash2[i-1]+s2[i]*ha[i];
		if(i>=s1.length()-1&&hash2[i]-hash2[i-s1.length()]==hash1[s1.length()-1]*ha[i-s1.length()+1]&&s2[i+1]==' '&&s2[i-s1.length()]==' ')
		{
			cnt++;
			if(first==-1)first=i-s1.length()+1;
		}
	}
	if(cnt)cout<<cnt<<" "<<first;
	else cout<<-1;
}
