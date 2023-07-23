#include<iostream>
#define int long long
using namespace std;
string a,b;
int s1[1000001],s2[1000001],ans[1000001];
signed main()
{
	cin>>a>>b;
	for(int i=0;i<a.length();i++)s1[i]=a[a.length()-1-i]-'0';
	for(int i=0;i<b.length();i++)s2[i]=b[b.length()-1-i]-'0';
	int len=max(a.length(),b.length());
	for(int i=0;i<len;i++)
	{
		ans[i]+=s1[i]+s2[i];
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	if(ans[len]!=0)cout<<ans[len];
	for(int i=len-1;i>=0;i--)cout<<ans[i];
}
