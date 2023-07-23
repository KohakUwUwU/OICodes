#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#define N 100005
using namespace std;
int A[26],B[26];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string a,b;
		cin>>a>>b; 
		for(int i=0; i<26; i++) A[i]=B[i]=0;
		for(int i=0; i<n; i++) ++A[a[i]-'a'];
		for(int i=0; i<n; i++) ++B[b[i]-'a'];
		bool f=1;
		for(int i=0; i<26; i++) if((A[i]-B[i])%k) f=0;
		for(int i=0,x=0,y=0; i<26; i++)
		{
			x+=A[i]/k,y+=B[i]/k;
			if(x<y) f=0;
		}
		if(f) puts("YES");
		else puts("NO");
	} 
}
