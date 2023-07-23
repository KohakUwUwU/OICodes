//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
一次增加超过一个周期的重量之和，模一下重量之和，等效。一个箱子的土豆数量答案需要加上周期数*周期
二分一下一次的范围
找到循环为止 
*/
const int N=2e5+5;
int n,q,x,w[N],a[N],pos_q[N],cnt,num_q[N];
unordered_map<int,int>ma;
inline int Sum(int pos,int len)
{
	int ans=0;
	ans+=len/n*a[n];
	len%=n;
	if(pos+len-1<=n)ans+=a[pos+len-1]-a[pos-1];
	else ans+=a[n]-a[pos-1]+a[len-n+pos-1];
	return ans;
}//n-pos+1 len-n+pos-1
signed main()
{
	cin>>n>>q>>x;
	for(int i=1;i<=n;i++)cin>>w[i],a[i]=a[i-1]+w[i];
	int ex=x/a[n]*n;
	x%=a[n];
	int gogo=log2(n)+1;
	int pos=1;
	for(int i=1;i<=n;i++)
	{
		int go=gogo,tr=0,alr=0;
		while(go>=0)
		{
			if(Sum(pos,(1<<go))+alr<=x)tr+=(1<<go),pos=(pos+(1<<go)-1)%n+1,alr+=Sum(pos,(1<<go));
//			cout<<Sum(pos,(1<<go))<<' '<<alr<<' '<<x<<'\n';
			go--;
		}
		tr++,pos=pos%n+2;
		++cnt;
		pos_q[cnt]=pos;
		num_q[cnt]=tr;
		ma[pos]=1;
	}
	for(int i=1;i<=q;i++)
	{
		int opt;
		cin>>opt;
		cout<<num_q[(opt-1)%n+1]+ex<<'\n';
	}
	return 0;
}

