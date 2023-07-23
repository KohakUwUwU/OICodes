//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int n,a[N],bin[4];
signed main()
{
	freopen("collaborator.in","r",stdin);
	freopen("collaborator.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]%=3,bin[a[i]]++;
	cout<<min(bin[1],bin[2])+bin[0]/2;
	return 0;
}

