#include<bits/stdc++.h>
using namespace std;
int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int b[26];
char a[200];
int main()
{
	int lena,maxn,minn,maxn_minn,j=0;
	scanf("%s",a);
	lena=strlen(a);
	for (int i=0;i<lena;i++)
	{
		b[a[i]-'a']++;
	}
	sort(b,b+26);
	int x=0;
	for (int i=0;i<26;i++)
	{
		if(b[i]==0)
		x++;
	}
	maxn=b[25];
	if(x==25)
	{
		minn=0;
	}
	else
	minn=b[x];
	maxn_minn=maxn-minn;
	for (int i=0;i<25;i++)
	{
		if(maxn_minn==prime[i])
		{	
		cout<<"Lucky Word"<<endl;
		cout<<maxn_minn<<endl;
		return 0;
		}
	}
	cout<<"No Answer"<<endl;
	cout<<0<<endl;
	return 0;
}
