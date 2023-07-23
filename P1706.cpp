//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=10;
int n;
int a[N];
signed main()
{
	cin>>n;
	int times=1;
	for(int i=1;i<=n;i++)times*=i,a[i]=i;
	for(int i=1;i<=times;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<fixed<<setw(5)<<a[j];
		}
		cout<<endl;
		next_permutation(a+1,a+1+n);
	}
	return 0;
}

