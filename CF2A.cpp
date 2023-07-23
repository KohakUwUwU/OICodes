#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int>m;
int mx=-1;
string mxn;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;int p;
		cin>>str>>p;
		m[str]+=p;
		if(m[str]>mx)mx=m[str],mxn=str;
	}
	cout<<mxn;
}
