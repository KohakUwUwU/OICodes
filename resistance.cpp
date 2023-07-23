//STD of Problem "Resistance"
//Idea:RD & AsakuraSayori
//STD:AsakuraSayori
#include<bits/stdc++.h>
#define N 300
using namespace std;
int n,m,s,t,u,v,l;
vector<int>e[N],d[N];//ÖÕ½Úµã ±ßÈ¨ 
inline int read()
{
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
	n=read();m=read();s=read();t=read();
	for(int i=1;i<=m;i++)
	{
		u=read();v=read();l=read();
		e[u].push_back(v);e[v].push_back(u);
		d[u].push_back(l);d[v].push_back(l);
	}
	
}
