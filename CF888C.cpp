#include<iostream>
#include<cstring>
using namespace std;
int a[130],maxl[130],maxll=10000000,once[130];
int main()
{
	string s;
	cin>>s;
	memset(a,-1,sizeof(a));
	memset(maxl,-1,sizeof(maxl));
	for(int i=0;i<s.length();i++)
	{
		if(a[s[i]]==-1)maxl[s[i]]=i+1,a[s[i]]=i,once[s[i]]=1;
		else
		{
//			cout<<i-a[s[i]]<<endl;
			maxl[s[i]]=max(i-a[s[i]],maxl[s[i]]);
			a[s[i]]=i;
			once[s[i]]=2;
		}
	}
	for(int i=0;i<s.length();i++)maxll=min(maxll,int((once[s[i]]==1)?(max(int(s.length()-maxl[s[i]]),maxl[s[i]])):(maxl[s[i]])));
	cout<<maxll;
}
