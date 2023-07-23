//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e7+1;
int ans,n,a[N],bin[100001],cnt;
queue<int>q1,q2;
inline void read(int &x)
{ 
	int f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	x*=f;
}
inline int Element()
{
	if(q2.empty()||!q1.empty()&&q1.front()<q2.front())
	{
		int x=q1.front();
		q1.pop();return x;
	}
	else
	{
		int x=q2.front();
		q2.pop();return x;
	}
}
signed main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),bin[a[i]]++;
	for(int i=1;i<=1e5;i++)for(int j=1;j<=bin[i];j++)q1.push(i);
	for(int i=1;i<n;i++)
	{
		int k=Element()+Element();
		ans+=k;q2.push(k);
	}
	cout<<ans;
	return 0;
}

