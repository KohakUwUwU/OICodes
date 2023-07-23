#include<bits/stdc++.h>
using namespace std; 
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline int Read(){
    char ch=getchar();
    int res=0;
    while(ch!='\n')
    {
	   if(isdigit(ch)) res=ch-48;
	   ch=getchar();
    }
    return res;
}
bitset<1003> bs[1003];
signed main()
{
	freopen("air.in","r",stdin);
	freopen("air.out","w",stdout);
 	int n=read();
 	for(int i=1; i<=n; ++i) 
 	{
 		bs[i][i]=1;
 		for(int m=read(); m--;) bs[read()][i]=1;
 	}
 	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
	if(bs[j][i]) bs[j]|=bs[i];
	double ans=0;
	for(int i=1; i<=n; ++i) ans+=1.0/bs[i].count();
	printf("%.5lf\n",ans);
	return 0;
}

