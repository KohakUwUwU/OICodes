//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+5;
int n,k,t[N],x[N],y[N];
inline void sub1()
{
	cout<<"Mystia will cook forever...";
}
inline bool checksub2()
{
	if(k>10)return false;
	for(int i=1;i<=k;i++)if(t[i]>10)return false;
	return true;
}
inline bool checksub3()
{
	for(int i=1;i<=k;i++)if(y[i])return false;
	return true;
}
inline void sub2()
{
	
}
inline int gcd(int x,int y)
{
	if(x<y)swap(x,y);
	if(y==1)return x;
	return gcd(x%y,y);
}
inline void sub3()
{
	int mn=114514114514;
	for(int i=1;i<=k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
			if(x[i]!=x[j])mn=min(mn,x[i]*x[j]/gcd(x[i],x[j]));
		}
	}
	if(mn==114514114514)
	{
		sub1();
		return ;
	}
	cout<<mn;
}
inline void sub4()
{
	
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>t[i]>>x[i]>>y[i];
	if(k==1)sub1();
	else if(checksub2())sub2();
	else if(checksub3())sub3();
	else sub4();
	return 0;
}

