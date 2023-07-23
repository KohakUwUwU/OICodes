//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[6];
signed main()
{
	for(int i=1;i<=5;i++)cin>>a[i];
	sort(a+1,a+6);
	if(a[1]==a[2]&&a[2]==a[3]&&a[3]!=a[4]&&a[4]==a[5]||a[1]==a[2]&&a[2]!=a[3]&&a[3]==a[4]&&a[4]==a[5])cout<<"Yes";
	else cout<<"No";
	return 0;
}

