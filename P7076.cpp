#include<iostream>
#include<cstdio>
#include<map>
#define N 1000005
using namespace std;
int n,m,c,k;
int bin[N][65],binofbin[65];
inline void binner(int pos,int num)
{
	int cnt=0;
	while(num){
		if(num%2==1)bin[pos][cnt]=1,binofbin[cnt]=1;
		cnt++;
		num/=2;
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		binner(i,tmp);
	}
	int tmp=0;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(binofbin[a]==0)++tmp;
	}
	cout<<(1<<(c-tmp-1))-n;
}
