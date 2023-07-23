//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[4]={1,2,3,4};
int p[5]={0,3,9,27,81};
inline int f(int a,int b,int c,int d)
{
	return abs(a-b)+abs(b-c)+abs(c-d);
}
signed main()
{
	for(int i=1;i<=24;i++)
	{
		for(int j=0;j<4;j++)cout<<a[j]<<' ';
		cout<<f(p[a[0]],p[a[1]],p[a[2]],p[a[3]])<<'\n';
		next_permutation(a,a+4);
	}
	return 0;
}

