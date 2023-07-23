//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int ocnt,ecnt,a[N],o[N],e[N],tod[N];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		ocnt=ecnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]%2)e[++ecnt]=a[i];
			else o[++ocnt]=a[i];
		}
		if(ocnt>0)
		{
			cout<<ecnt<<'\n';
			continue;
		}
		else
		{
			int mint=114514114514;
			for(int i=1;i<=n;i++)
			{
				tod[i]=0;
				int tmp=a[i];
				while(tmp%2==0)tmp/=2,tod[i]++;
				mint=min(mint,tod[i]);
			}
			cout<<mint+n-1<<'\n';
		}
	}
	return 0;
}

