//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,a[2*N]; 
signed main()
{
	cin>>n;
	if(n%2==0)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
	{
		a[i]=2*i-1,a[i+n]=2*i;
		if(i%2==0)swap(a[i],a[i+n]); 
	}
	for(int i=1;i<=2*n;i++)cout<<a[i]<<' ';
	return 0;
}

