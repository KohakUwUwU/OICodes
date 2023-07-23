#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=55;
double arr[N];
signed main()
{
	int r;
	while(1)
	{
		cin>>r;
		for(int i=0;i<=r;i++)arr[i]=sqrt(r*r-i*i);
		for(int i=0;i<=r;i++)cout<<i<<' '<<arr[i]<<'\n';
	}
	return 0;
}