#include <bits/stdc++.h>
using namespace std;
__int128 f[800][800],ans;
__int128 n,m,a[800][800];
__int128 read()
{
	__int128 s=0;
	char c=getchar();
	while(c>57||c<48) c=getchar();
	while(47<c&&c<58) 
	{
		s=s*10;
		s=s+c-48;
		c=getchar();
	}
	return s;
}
inline void print(__int128 x){if(x>9) print(x/10);putchar(x%10+48);} 
__int128 ksm(__int128 a,__int128 b)
{
	__int128 s=1;
	while(b)
	{
		if(b%2) s*=a;
		a=a*a;
		b>>=1;
	}
	return s;
}
__int128 dp(int l,int r,int x,int s)
{
	if(f[l][r]) return f[l][r];
	if(l>r) return 0;
	f[l][r]=max(dp(l+1,r,x,s+1)+a[x][l]*(ksm(2,s)),dp(l,r-1,x,s+1)+a[x][r]*(ksm(2,s)));
	return f[l][r];
}
int main() 
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read();
	for(int i=1;i<=n;i++){memset(f,0,sizeof(f));ans=ans+dp(1,m,i,1);}//ans为所有行之和 
	print(ans);
	return 0;
}
