//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,q[N],s[N],cnt,ans;
pair<int,int>a[N],b[N];
inline void print_q()
{
	for(int i=1;i<=n;i++)cout<<q[i]<<' ';
	cout<<'\n';
}
inline void msort(int l,int r)
{
	if(l==r)return ;
	int mid=l+r>>1;
	msort(l,mid);
	msort(mid+1,r);
	int x=l,y=mid+1;
	cnt=0;
//	cout<<x<<' '<<y<<'\n';
	while(1)
	{
		if(x>mid)
		{
			if(y>r)break;
			s[++cnt]=q[y],y++;
		}
		else
		{
			if(y>r)s[++cnt]=q[x],x++;
			else
			{
				if(q[x]<q[y])s[++cnt]=q[x],x++;
				else s[++cnt]=q[y],y++,ans+=(mid-x+1);
			}
		}
//		cout<<x<<' '<<y<<'\n';
//		print_q();
	}
	for(int i=1;i<=cnt;i++)q[l+i-1]=s[i];
//	cout<<'\n';
	//1 3 4 2
	//1 7 2 4
	//1 3 4 2
	//1 4 2 3
	//1 3 4 2
	//(3,2) (4,2)
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
	for(int i=1;i<=n;i++)cin>>b[i].first,b[i].second=i;
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)q[a[i].second]=b[i].second;
//	for(int i=1;i<=n;i++)cout<<q[i]<<' ';
//	cout<<'\n';
	msort(1,n);
//	print_q();
	cout<<ans%(int)(1e8-3);
	return 0;
}
