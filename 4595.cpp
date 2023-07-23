#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct z{
	int Len;
	ll Has;
} g[30][5005];
map<long long,int>L;
map<long long,ll>f,num;
map<long long,char>a;
int n,m,Len,cnt[30];
ll p;
char s[5005];
bool cmp(z a,z b){return a.Len>b.Len;}
int main(){
	scanf("%d%s",&n,&a);
	num[0]=1;
	for(int i=0;i<n;i++)f[i]=f[i-1]*233+a[i],num[i+1]=num[i]*233;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",&s);
		Len=strlen(s);
		int mb=s[Len-1]-'a';
		p=0;
		for(int j=0;j<Len;j++)p=p*233+s[j];
		g[mb][++cnt[mb]]=(z){Len,p};
	}
	for(int i=0;i<26;i++)sort(g[i]+1,g[i]+cnt[i]+1,cmp);
	for(int i=0;i<n;i++){
		int mb=a[i]-'a';
		for(int j=1;j<=cnt[mb];j++){
			Len=g[mb][j].Len;
			if(i<Len-1)continue;
			if(f[i]-f[i-Len]*num[Len]==g[mb][j].Has){
				L[i-Len+1]++,L[i+1]--;
				break;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(i>0)L[i]+=L[i-1];
		if(L[i]==0)ans++;
	}
	cout<<ans;
}
