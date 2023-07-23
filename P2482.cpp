#include<iostream>
#include<queue>
#include<cstdio>
#define N 12
#define M 2005
#define R register
using namespace std;
queue<char>pig[N],card;
int n,m;
int pt[N];
bool alive[N],X[N];//alive:true->die X:true->equiped
inline void INIT()
{
	R string typ;
	char input;
	scanf("%d%d",&n,&m);
	for(R int i=1;i<=n;i++)
	{
		cin>>typ;
		if(typ=="MP")pt[i]=1;
		else if(typ=="ZP")pt[i]=2;
		else pt[i]=3;
		for(R int j=1;j<=4;j++)
		{
			scanf("%c",&input);
			pig[i].push(input);
		}
	}
	for(R int i=1;i<=m;i++)
	{
		scanf("%d",&input);
		card.push(input);
	}
}
inline void FINDPIG()
{
	
}
inline void PLAY()
{
	R int current=0;
	while(1)
	{
		++current;
		if(current>n)current-=n;
		if(alive[current])continue;
		R char i1;
		i1=card.front();card.pop();pig[current].push(i1);
		i1=card.front();card.pop();pig[current].push(i1);
		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	INIT();
	PLAY();
}//注意一个角色的死亡会导致一些猪距离的改变
