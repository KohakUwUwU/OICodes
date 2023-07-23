#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void print(int x) {
    if(x>9) print(x/10);
    *O++=x%10+'0';
}
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
int main()
{
	for(int i=1,q=read();i<=q;i++)
	{
		int opt=read();
		if(opt==1)
		{
			string str=read();int hp=read();
		}
		if(opt==2)
		{
			string u,v;
		}
	}
}
