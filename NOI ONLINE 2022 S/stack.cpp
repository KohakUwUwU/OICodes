



//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,q,a[N],b[N],l[N],r[N],s[N];
int st[N],cnt;
inline int check()
{
	if(n<=1000&&q<=1000)return 1;
	if(n<=5000)return 2;
	if(n<=100000&&q<=100000)return 3;
	int s4=0,s5=0,s6=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=n-i+1)s4=1;
		if(a[i]!=i)s5=1;
	}
	if(!s4)return 4;
	if(!s5)return 5;
	return 6;
}
inline void print()
{
	for(int i=1;i<=cnt;i++)cout<<s[i]<<' ';
	cout<<'\n';
}
inline void run1()
{
	int ans=0;
	for(int i=1;i<=q;i++)
	{
		cnt=0;
		ans=0;
		for(int j=l[i];j<=r[i];j++)
		{
			while(cnt>0&&(a[j]==a[s[cnt]]||b[j]>=b[s[cnt]]))--cnt;
			s[++cnt]=j;
//			print();
			if(cnt==1)ans++;
		}
		cout<<ans<<'\n';
	}
}
int eq[N];
inline void run2()
{
	int ans=0;
	int last=-1;
	for(int i=n;i>=1;i--)
	{
		if(last==a[i])eq[i]=eq[i+1];
		else
		{
			eq[i]=i;
			last=a[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int tot=min(r[i],eq[l[i]]);
		cout<<tot-l[i]+1<<'\n';
	}
}
signed main()
{
	freopen("stack.in","r",stdin);
	freopen("stack.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=q;i++)cin>>l[i]>>r[i];
	int opt=check();
	if(opt==1)run1();
	else if(opt==2)run1();
	else if(opt==4)run2();
	else if(opt==5)run1();
	else run1();
	return 0;
}
