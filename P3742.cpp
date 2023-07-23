#include<iostream>
using namespace std;
int main()
{
	int n;
	string s1,s2,str;
	cin>>n>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		if(s1[i]<s2[i])
		{
			cout<<"-1";
			return 0;
		}
		str+=min(s1[i],s2[i]);
	}
	cout<<str;
}
