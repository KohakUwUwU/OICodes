//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,a[N];
inline void qsort(int l,int r)
{
	int x=l,y=r;
	if(l==r)return ;
	int mid=a[l+r>>1];
	do
	{
		while(a[x]<mid)x++;
		while(a[y]>mid)y--;
		if(x<=y)swap(a[x],a[y]),x++,y--;
	}while(x<=y);
	if(l<y)qsort(l,y);
	if(x<r)qsort(x,r);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}

