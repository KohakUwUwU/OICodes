#include<stdio.h>
#include<algorithm>
inline int read()
{
	int a=0;char c;
	while((c=getchar())<'0');
	while(c>='0')a=a*10+(c^48),c=getchar();
	return a;
}
struct Pair
{
	int a,b;
	bool operator<(const Pair&q)const
	{
		return a==q.a?b<q.b:a<q.a;
	}
}x[100005];
int l[100005]; 
int main()
{
	int n=read(),k=read(),i,sum(0);
	for(i=0;i<=n;i++)l[i]=-1;
	for(i=0;i<k;i++)x[i].a=read(),x[i].b=read(); 
	std::sort(x,x+k);
	for(i=0;i<k;i++)
	{
		if(l[x[i].b-1]==x[i].a)sum++;
		if(l[x[i].b]==x[i].a-1)sum++;
		l[x[i].b]=x[i].a;
	}
	printf("%d",sum);
	return 0;
}
