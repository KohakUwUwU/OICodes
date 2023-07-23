//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

string str;
string as;//答案串 
int res=114514114514,cnt=114514114514;
char gp1[10]={'a','H','I','N','O','S','X','Z','M','W'};
char gp2[10]={'a','H','I','N','O','S','X','Z','W','M'};
int tag[55],anstag[55];
inline int ec(char i)
{
	return min(i-'A'+1,'Z'-i+1);
}
inline int ct(char from,char to)
{
	return abs(from-to);
}
inline int calc()
{
	int xhy=0;
	for(int i=0;i<str.length();i++)if(!tag[i])xhy++;
	return xhy;
}
inline void check(int ii,int jj)
{
	memset(tag,0,sizeof(tag));
	int l=ii,r=jj;int ret=0;
	while(l>=0&&r<str.length())
	{
		if(l==r)
		{
			int ans=ec(str[l]);
			for(int i=1;i<=8;i++)
			{
				ans=min(ans,ct(gp1[i],str[l]));
				if(ct(gp1[i],str[l])<=ans)ans=ct(gp1[i],str[l]),tag[l]=i;
			}
			ret+=ans;
			l--;r++;
			continue;
		}
		int ans=ec(str[l])+ec(str[r]);
		for(int i=1;i<=10;i++)
		{
			if(ct(gp1[i],str[l])+ct(gp2[i],str[r])<=ans)ans=ct(gp1[i],str[l])+ct(gp2[i],str[r]),tag[l]=i,tag[r]=-i;
		}
		ret+=ans;
		l--;r++;
	}
	if(l<0)
	{
		for(int i=r;i<str.length();i++)ret+=ec(str[i]);
	}
	else
	{
		for(int i=0;i<=l;i++)ret+=ec(str[i]);
	}
	if(ret<res||ret==res&&calc()<cnt)
	{
		for(int i=0;i<str.length();i++)anstag[i]=tag[i];
		res=ret;
	}
}
signed main()
{
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.length();i++)//枚举中心点 
	{
		check(i,i);
	}
	for(int i=0;i<str.length()-1;i++)//枚举中心两个点 
	{
		check(i,i+1);
	}
	for(int i=0;i<str.length();i++)
	{
		if(!anstag[i])continue;
		cout<<((anstag[i]>0)?gp1[anstag[i]]:gp1[-anstag[i]]);
	}
	return 0;
}

