#include<iostream>
using namespace std;
int fail[10001];
void getFail(string P)
{
	int m=P.length();
	fail[0]=-1;
	for(int i=1;i<m;i++)
	{
		int j=fail[i-1];
		while(j>=0&&P[j+1]!=P[i])j=fail[j];
		if(P[j+1]==P[i])j++;
		fail[i]=j;
	}
}
int KMP(string P,string T)
{
	int m=P.length(),n=T.length();
	int match=-1;
	for(int i=0;i<n;i++)
	{
		while(match>=0&&P[match+1]!=T[i])match=fail[match];
		if(P[match+1]==T[i])
		{
			match++;
			if(match+1==m)return i-m+1;
		}
	}
	return -1;
}
int main()
{
	string s,t;
	cin>>s>>t;
	getFail(t);
	cout<<KMP(s,t);
}
