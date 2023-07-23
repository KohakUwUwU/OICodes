//And in that light, I find deliverance.
#include<bits/stdc++.h>
using namespace std;
//printf scanf

typedef unsigned int in;
in work(in x)
{
	in s=x&(-x);
	in r=s+x;
	in n=r|(((x^r)>>2)/s);
	return n;
}
signed main()
{
	in n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++)n=work(n);
	cout<<n;
	return 0;
}

