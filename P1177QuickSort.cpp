//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,a[N];
#define mid (l+r>>1)
inline void QuickSort(int l,int r)
{
	if(l>=r)return ;
	int x=l,y=r,z=a[l];
	while(x<y)
	{
		while(x<y&&a[y]>z)y--;
		if(x<y)a[x++]=a[y];
		while(x<y&&a[x]<z)x++;
		if(x<y)a[y--]=a[x];
	}
	a[x]=z;
	QuickSort(l,x-1);
	QuickSort(x+1,r);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	QuickSort(1,n);
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}

