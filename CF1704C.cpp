//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,aa[N],a[N],num[N],cnt,l,r,Minus,ans;
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cnt=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++)cin>>aa[i];
		sort(aa+1,aa+1+m);
		for(int i=1;i<m;i++)if(aa[i+1]!=aa[i]+1)a[++cnt]=aa[i+1]-aa[i]-1;
		if(!(aa[1]==1&&aa[m]==n))a[++cnt]=aa[1]+n-aa[m]-1;
		sort(a+1,a+1+cnt);
		int l=1,r=1;
		while(r<=n)
		{
			while(a[r]==a[l]&&r<=n)r++,num[l]++;
			if(r<=n)a[++l]=a[r];
		}
		cnt=l;
		cout<<"!";
		l=1,r=cnt,Minus=0,ans=0;
		while(l<r)
		{
			cout<<"@";
			while(a[l]-Minus>0&&l<r)
			{
				cout<<"#";
				while(a[l]-Minus>0&&l<r&&num[r])
				{
					cout<<"$";
					num[r]--;
					ans+=a[r]-1-Minus;
					Minus+=4;
				}
				if(l<r)r--;
				cout<<"%";
			}
			cout<<"^";
			if(l==r)
			{
				cout<<"&";
				while(a[l]-Minus>0&&num[r])
				{
					cout<<"*";
					ans+=a[l]-Minus-1;
					Minus+=4;
					num[r]--;
				}
				cout<<"(";
				cout<<ans<<'\n';
				break;
			}
			else
			{
				cout<<")";
				while(a[l]-Minus<0&&l<=r)cout<<"-",l++;
				if(a[r]-Minus<=0)
				{
					cout<<ans<<'\n';
					break;
				}
			}
		}
		cout<<"_";
	}
	return 0;
}

