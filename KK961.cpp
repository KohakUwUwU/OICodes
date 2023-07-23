#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int bl=330;
int a[100003];
int mx[330],tag[330];
signed main()
{
	freopen("brain12.in","r",stdin);
	freopen("brain12.out","w",stdout);
	int n=read(),m=read();
	memset(mx,0xc0,sizeof(mx)),memset(a,0xc0,sizeof(a));
	for(int i=0; i<n; i++) a[i]=read(),mx[i/bl]=max(mx[i/bl],a[i]);
	for(;m--;)
	{
		int opt=read(),l=read()-1,r=read()-1;
		int k=read();
		int pl=l/bl,pr=r/bl;
		if(opt==1)
		{
			if(pl==pr)
			{
				for(int i=l; i<=r; i++) a[i]+=k;
				mx[pl]=0xc0c0c0c0c0c0c0c0;
				for(int i=pl*bl; i<(pl+1)*bl; ++i) mx[pl]=max(mx[pl],a[i]);
			}
			else
			{
				int R=(pl+1)*bl;
				for(int i=l; i<R; i++) a[i]+=k;
				mx[pl]=0xc0c0c0c0c0c0c0c0;
				for(int i=pl*bl; i<(pl+1)*bl; ++i) mx[pl]=max(mx[pl],a[i]);
				int L=pr*bl;
				for(int i=L; i<=r; i++) a[i]+=k;
				mx[pr]=0xc0c0c0c0c0c0c0c0;
				for(int i=pr*bl; i<(pr+1)*bl; ++i) mx[pr]=max(mx[pr],a[i]);
				for(int i=pl+1; i<pr; i++) tag[i]+=k;			
			}
		}
		else//query
		{
			if(pl==pr)
			{
				int ans=0xc0c0c0c0c0c0c0c0;
				for(int i=l; i<=r; i++) ans=max(ans,a[i]+tag[pl]);
				printf("%lld\n",ans);
			}
			else
			{
				int ans=0xc0c0c0c0c0c0c0c0;
				int pl=l/bl,pr=r/bl;
				int R=(pl+1)*bl;
				for(int i=l; i<R; i++) ans=max(ans,a[i]+tag[pl]);
				int L=pr*bl;
				for(int i=L; i<=r; i++) ans=max(ans,a[i]+tag[pr]);
				for(int i=pl+1; i<pr; i++) ans=max(ans,mx[i]+tag[i]); 
				printf("%lld\n",ans);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

