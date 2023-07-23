//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int q=m/n;
		int r=m%n;
		if(r==0)
		{
			cout<<"Yes\n";
			for(int i=1;i<=n;i++)cout<<q<<' ';
			cout<<'\n';
			continue;
		}
		if(n%2==1)
		{
			cout<<"Yes\n";
			for(int i=1;i<n;i++)cout<<q<<' ';
			cout<<q+r<<'\n';
			continue;
		}
		else
		{
			int ans=-1,len;
			for(int i=1;i*i<=r;i++)
			{
				if(i>n)break;
				if(r%i!=0)continue;
				if((n-i)%2!=0)continue;
				ans=r/i;len=i;break;
			}
			if(ans!=-1)
			{
				cout<<"Yes\n";
				for(int i=1;i<=n-len;i++)cout<<q<<' ';
				for(int i=n-len+1;i<=n;i++)cout<<q+ans<<' ';
				cout<<'\n';
				continue;
			}
			for(int pre=2;pre<=r;pre+=2)
			{
				int ans=-1,len;
				for(int i=1;i*i<=r-pre;i++)
				{
					if(i>n-2)break;
					if((r-pre)%i!=0)continue;
					if((n-i)%2!=0)continue;
					ans=(r-pre)/i;len=i;
					break;
				}
				if(len+2>n||ans==-1)continue;
				cout<<"Yes\n";
				for(int i=1;i<=n-len-2;i++)cout<<q<<' ';
				cout<<q+pre/2<<' '<<q+pre/2<<' ';
				for(int i=n-len+1;i<=n;i++)cout<<q+ans<<' ';
				cout<<'\n';
				break;
			}
			cout<<"No\n";
		}
	}
	return 0;
}

