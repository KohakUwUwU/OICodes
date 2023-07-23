//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
const int INF=114514114514;
int n,w[N],t[N],cnt,a[N],f[N];
string str; 
//w ÊÇ value
//t ÊÇ type
inline bool check_same()
{
	int aa=t[1];
	for(int i=1;i<=n;i++)if(t[i]!=aa)return false;
	return true;
}
signed main()
{
	freopen("panghu.in","r",stdin);
	freopen("panghu.out","w",stdout);
	cin>>n>>str;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=0;i<n;i++)t[i+1]=str[i]-'A';
	if(check_same())
	{
		cout<<0;
		return 0;
	}
	int st=0,ed=n+1;
	int stt=t[1],edd=t[n];
	while(t[++st]==stt);
	while(t[--ed]==edd);
	if(st>ed)
	{
		cout<<0;
		return 0;
	}
	++cnt;
	for(int i=2;i<st;i++)a[cnt]=max(a[cnt],w[i]);
	++cnt;
	int last=t[st];
	for(int i=st;i<=ed;i++)
	{
		if(last==t[i])
		{
			a[cnt]=max(a[cnt],w[i]);
			continue;
		}
		last=t[i];
		a[++cnt]=w[i];
	}
	++cnt;
	for(int i=ed+1;i<n;i++)a[cnt]=max(a[cnt],w[i]);
	f[1]=a[1];
	f[2]=a[2];
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i-2;j++)f[i]=max(f[i],f[j]+a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}

