#include<stdio.h>
#include<bits/stdc++.h>
int m,n,ans;
int main(){
	scanf("%d%d",&m,&n);
	if(m==n)ans--;
	n*=m;
	for(int i=1;i*i<=n;i++)if(n%i==0&&std::__gcd(i,n/i)==m)ans+=2;
	printf("%d",ans);
}
