#include<bits/stdc++.h>
#define N (int)1e5+5
using namespace std;//Áå½´ÌùÌù£¡ÓÀÔ¶µÄÉñ£¡ 
int n,m,c;
int light[N];
bool color[N];
int seg
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
inline void build(int pos,int l,int r)
{
	
}
int main()
{
	n=read();m=read();c=read();
	for(int i=1;i<=n;i++)cin>>light[i];
	build(0,)
	for(int i=1;i<=m;i++)cin>>
	{
		int p;
		cin>>p;
		color[p]=!color[p];
		int cnt=0;
		bool state=false;
		for(int i=1;i<=n;i++)
		{
			if(color[light[i]]&&(state^color[light[i]]))cnt++,state=true;
			else if(color[light[i]])continue;
			else state=false;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
