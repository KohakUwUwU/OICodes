#include<bits/stdc++.h>
using namespace std;
bool check(string str,char a,char b,char c)
{
	stack<int>st;
	for(int i=0;i<str.length();i++)
	{
		char d;
		if(str[i]=='A')d=a;
		if(str[i]=='B')d=b;
		if(str[i]=='C')d=c;
		if(d==')')
		{
			if(st.empty())return false;
			st.pop();
		}
		else
		{
			st.push(1);
		}
	}
	if(st.empty())return true;
	else return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		if(check(str,'(','(',')')||check(str,')',')','(')||check(str,'(',')','(')||check(str,')','(',')')||check(str,'(',')',')')||check(str,')','(','('))cout<<"YES\n";
		else cout<<"NO\n";
	}
}
