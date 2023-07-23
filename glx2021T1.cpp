#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int maxn=1e7+1005;
int T,x,fok[maxn];
bool nok[maxn];

bool chk(int x){
	for(;x;x/=10)if(x%10==7)return 1;
	return 0;
}

void prework(int n){
	rep(i,1,n)if(!nok[i]){
		if(chk(i))for(int j=i;j<=n;j+=i)nok[j]=1;
	}
	per(i,n,1)fok[i]=nok[i]?fok[i+1]:i;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number2.out","w",stdout);
	prework(maxn-5);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		printf("%d\n",nok[x]?-1:fok[x+1]);
	}
	return 0;
}

