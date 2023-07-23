//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
signed main()
{
	cin>>n;
	int tmp=1,sum=0;
	for(int i=1;i<=n;i++)
	{
		tmp*=i;//1 2 6
		sum+=tmp;//0->1->3->9
	}
	cout<<sum;
	return 0;
}

