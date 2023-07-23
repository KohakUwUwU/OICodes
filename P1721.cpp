//Project Sekai
#include<bits/stdc++.h>
#define int long long
//#define double long double
using namespace std;

const int N=8e3+5;
int n,k,p;
double h[N];
inline bool check1()//1 2 3
{
	//暴力dfs 
	return n<=4&&k<=5||n<=10&&k<=2;
}
inline bool check2()//4 8
{
	//从高到低枚举 持续贡献 
	return k==1;
}
inline bool check3()//n<=k
{
	//n<=k 从小到大走
	return n<=k;
}
inline void Input()
{
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)cin>>h[i];
}
double ans=-114514;
inline void dfs_bf(int step)
{
	double tmp[15];
	if(step==k+1)
	{
//		cout<<"check4:"<<h[1]<<' '<<h[2]<<' '<<h[3]<<'\n';
		ans=max(ans,h[1]);
		return ;
	}
	for(int i=0;i<(1<<n);i++)
	{
//		cout<<"check1:"<<h[1]<<' '<<h[2]<<' '<<h[3]<<'\n';
		int mode=i,j=1,cnt=0;
		double sum=0;
		while(mode)
		{
			if(mode%2==0)
			{
				mode/=2;
				j++;
				continue;
			}
			sum+=h[j];
			tmp[j]=h[j];
			cnt++;
			mode/=2;
//			cout<<j<<' ';
			j++;
		}
//		cout<<'\n';
		double avr=sum/(double)cnt;
		mode=i,j=1;
//		cout<<"check2:"<<h[1]<<' '<<h[2]<<' '<<h[3]<<'\n';
//		cout<<"check2.5:"<<tmp[1]<<' '<<tmp[2]<<' '<<tmp[3]<<'\n';
		while(mode)
		{
			if(mode%2==0)
			{
				mode/=2;
				j++;
				continue;
			}
			h[j]=avr;
			mode/=2;
			j++;
		}
//		cout<<"check3:"<<h[1]<<' '<<h[2]<<' '<<h[3]<<'\n';
		dfs_bf(step+1);
//		cout<<"check5:"<<h[1]<<' '<<h[2]<<' '<<h[3]<<'\n';
		mode=i,j=1;
		while(mode)
		{
			if(mode%2==0)
			{
				mode/=2;
				j++;
				continue;
			}
			h[j]=tmp[j];
			mode/=2;
//			cout<<j<<' ';
			j++;
		}
//		cout<<"check6:"<<h[1]<<' '<<h[2]<<' '<<h[3]<<'\n'<<'\n';
	}
}
inline void run1()
{
	if(n==1)
	{
		cout<<fixed<<setprecision(2*p)<<h[1];
		return ;
	}
	dfs_bf(1);
	cout<<fixed<<setprecision(2*p)<<ans;
}
inline void run2()
{
	sort(h+2,h+1+n);
	int first=2;
	while(h[first]<=h[1]&&first<=n)first++;
	if(first==n+1)
	{
		cout<<fixed<<setprecision(2*p)<<h[1];
		return ;
	}
//	cout<<first<<'\n';
//	for(int i=1;i<=n;i++)cout<<h[i]<<' ';
//	cout<<'\n';
	double sum=h[n]+h[1];
	for(int i=n-1;i>=first;i--)
	{
//		cout<<sum/(double)(n-i+1)<<' '<<(sum+h[i])/(double)(n-i+2)<<'\n';
		if(sum/(double)(n-i+1)<(sum+h[i])/(double)(n-i+2))sum+=h[i];
		else
		{
			cout<<fixed<<setprecision(2*p)<<sum/(double)(n-i+1);
			return ;
		}
	}
}
inline void run3()
{
	sort(h+2,h+1+n);
	int first=2;
	while(h[first]<=h[1]&&first<=n)first++;
	if(first==n+1)
	{
		cout<<fixed<<setprecision(2*p)<<h[1];
		return ;
	}
	for(int i=first;i<=n;i++)h[1]=h[i]=(h[1]+h[i])/(double)(2);
	cout<<h[1];
}
inline void dfs_insert(int pos,int step)
{
	if(step==k||pos==n)
	{
		double sum=h[1];
		for(int i=pos+1;i<=n;i++)sum+=h[i];
		ans=max(ans,sum/(double)(1+n-pos));
		return ;
	}
	int orih1=h[1],sum=h[1];
	for(int i=pos+1;i<=n;i++)
	{
		sum+=h[i];
		h[1]=sum/(double)(1+i-pos);
		dfs_insert(i,step+1);
	}
	h[1]=orih1;
}
inline void run4()//插板 
{
	sort(h+2,h+1+n);
	int first=2;
	while(h[first]<=h[1]&&first<=n)first++;
	if(first==n+1)
	{
		cout<<fixed<<setprecision(2*p)<<h[1];
		return ;
	}
	dfs_insert(first-1,1);
	cout<<fixed<<setprecision(2*p)<<ans;
}
signed main()
{
	Input();
	if(check1())run1();
	else if(check2())run2();
	else if(check3())run3();
	else run4();
	return 0;
}
