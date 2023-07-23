//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1<<16;
int n,a[N];
inline int lowbit(int k)
{
	return k&-k;
}
inline int pop(int k)
{
	int cnt=0;
	while(k)k-=lowbit(k),cnt++;
	if(cnt&1)return 1;
	else return -1;
}
signed main()
{
	freopen("school.in","r",stdin);
	freopen("school.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<(1<<n);i++)cin>>a[i],sum+=pop(i)*a[i];
	cout<<sum;
	return 0;
}

