#include<iostream>
#include<cstdio>
using namespace std;
long long n,k;
long long que[1000001];
short bin[1000001][33],bink[33];
int time;
bool judge(int x,int y)
{
	for(int i=1;i<=32;i++)
	{
		bool t;
		if(bin[x][i]==bin[y][i])t=false;
		else t=true;
		if(t>bink[i])return false;
	}
	return true;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		long long tmp;
		scanf("%lld",&tmp);
		que[i]=tmp;
		while(tmp)
		{
			bin[i][33-(++bin[i][0])]=tmp%2;
			tmp/=2;
		}
	}
	long long tmp;
	tmp=k;
	while(tmp)
	{
		bink[33-(++bink[0])]=tmp%2;
		tmp/=2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(judge(i,j))time++;
		}
	}
	cout<<time;
	return 0;
}
