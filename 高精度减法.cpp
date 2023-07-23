#include<iostream>
using namespace std;
string a,b;
int s1[1001],s2[1001],ans[1001],flag;
int main()
{
	cin>>a>>b;
	for(int i=0;i<a.length();i++)
	  s1[i]=a[a.length()-1-i]-'0';
	for(int i=0;i<b.length();i++)
	  s2[i]=b[b.length()-1-i]-'0';
	int len=max(a.length(),b.length());
	for(int i=0;i<len;i++)
	{
		ans[i]=s1[i]-s2[i];
		if(ans[i]<0) 
		 {
			ans[i]+=10;
			s1[i+1]--;
		 }
		if(ans[i]!=0)flag=i;
	}
	for(int i=flag;i>=0;i--)cout<<ans[i];
	
}

