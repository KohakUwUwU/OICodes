//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,a[N],b[N],ans;
#define mid (l+r>>1)
inline void MergeSort(int l,int r)
{
//	cout<<l<<' '<<r<<'\n';
	if(l==r)return ;
	MergeSort(l,mid);MergeSort(mid+1,r);
	int x=l,y=mid+1,p=l;
	while(x<=mid&&y<=r)
	{
		if(a[x]<=a[y])b[p++]=a[x++];
		else
		{
			b[p++]=a[y++];
			ans+=mid-x+1;
		}
	}
	while(x<=mid)b[p++]=a[x++];
	while(y<=r)b[p++]=a[y++];
	for(int i=l;i<=r;i++)a[i]=b[i];
}
signed main()
{
//	freopen("P1908_6.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	MergeSort(1,n);
	cout<<ans;
	return 0;
}

