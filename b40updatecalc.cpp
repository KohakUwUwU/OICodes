//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[100];
signed main()
{
	for(int i=1;i<=40;i++)cin>>a[i];
	sort(a+1,a+1+40);
	int sum=0;
	for(int i=1;i<=25;i++)sum+=a[i];
	cout<<sum;
	return 0;
}

