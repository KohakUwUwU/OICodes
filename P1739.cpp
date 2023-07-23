#include<bits/stdc++.h>
using namespace std;
stack<int> G;
int main()
{
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='(')G.push(1);
		if(a[i]==')')
		{
			if(G.empty())
			{
				cout<<"NO";
				return 0;
			}
			G.pop();
		}
	}
	if(G.empty())cout<<"YES";
	else cout<<"NO"; 
}
