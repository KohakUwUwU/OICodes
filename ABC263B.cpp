//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=55;
int n,a[N]; 
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)cin>>a[i],a[i]--;
	int p=n-1,cnt=0;
	while(p)p=a[p],cnt++;
	cout<<cnt;
	return 0;
}

