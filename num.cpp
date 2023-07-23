#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
long long x,k;
map<long long,long long>prime;//qwq°´Í°´¢´æ 
map<long long,long long>prime1;//qwq°´Ë³Ðò´¢´æ 
long long mi[1000001];
long long num=0,minum=0;
bool cmp(long long a,long long b)
{
	return a>b;
}
void as()
{
	for(long long i=2;i*i<=x;i++)
	{
		if(prime[i]==0)
		{
			if(x%i==0)
			{
				long long mul=1;
				while(x%i==0)
				{
					mul*=i;
					x/=i;
				}
				mi[++minum]=mul;
				if(x==1)return;
			}
			prime1[++num]=i;
			for(int j=i*i;j*j<=x;j+=i)prime[j]=1;
		}
	}
}
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	cin>>x>>k;
	as();
	mi[++minum]=1;
//	for(long long i=num;i>=1;i--)
//	{
//		if(x%prime1[i]==0)
//		{
//			long long mul=1;
//			while(x%prime1[i]==0)
//			{
//				mul*=prime1[i];
//				x/=prime1[i];
//			}
//			mi[++minum]=mul;
//		}
//		if(x==1)break;
//	}
	sort(mi+1,mi+1+minum,cmp);
	for(long long i=1;i<=k;i++)cout<<mi[i]<<" ";
	return 0;
}
