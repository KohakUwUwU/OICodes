//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

int k;
signed main()
{
	cin>>k;
	int n=0;
	double sum=0;
	while(sum<=k)
	{
		n++;
		sum+=1.0/(double)n;
	}
	cout<<n;
	return 0;
}
