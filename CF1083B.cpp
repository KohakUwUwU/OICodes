//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,k;
string s,t;
int curk,ans;
priority_queue<int>q[N];
inline void print_ans()
{
	cout<<"ans="<<ans<<'\n';
}
signed main()
{
	cin>>n>>k;
	curk=k-2,ans=2*n;
	cin>>s>>t;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!=t[i])
		{
			flag=i;
			break;
		}
	}
	for(int i=flag+1;i<n;i++)
	{
		if(s[i]=='b')continue;
		int m=n-i;
		q[m].push(0);
		for(int j=1;m-j>=1;j++)q[m-j].push(j-1);
	}
	for(int i=flag+1;i<n;i++)
	{
		if(t[i]=='a')continue;
		int m=n-i;
		q[m].push(0);
		for(int j=1;m-j>=1;j++)q[m-j].push(j-1);
	}
	for(int i=n;i>=1;i--)
	{
//		cout<<i<<':'<<'\n';
//		print_ans();
		while(!q[i].empty())
		{
			int tt=q[i].top();
//			cout<<tt<<'\n';
			q[i].pop();
			if((double)tt>=log(curk)/log(2))
			{
				ans+=curk*i,curk=0;
				break;
			}
			else
			{
				ans+=(1<<tt)*i;
				curk-=(1<<tt);
			}
//			print_ans();
		}
		if(curk==0)
		{
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}

