#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
struct data
{
	int pos;
	long long ans;
};
map<int,bool>bin;
queue<data>q;
int l,s,t,m,tmp;
long long minn=0x3f3f3f3f3f3f3f3f;
int main()
{
	scanf("%d%d%d%d",&l,&s,&t,&m);
	for(int i=1;i<=m;i++)scanf("%d",&tmp),bin[tmp]=true;
	data k;
	k.pos=0;k.ans=bin[0]==true?1:0;
	q.push(k);
	while(!q.empty())
	{
		int n=q.front().pos;
		for(int i=s;i<=t&&n+i<=l;i++)
		{
			k.ans=q.front().ans+bin[n+i]==true?1:0;
			k.pos=n+i;
			if(k.pos==l)minn=min(minn,k.ans);
			else q.push(k);
		}
		q.pop();
	}
	printf("%lld",minn);
}
