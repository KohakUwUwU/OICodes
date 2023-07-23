#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int tree[100003],a[100003],lsh[100003],ans[100003];
void add(int x)
{
	while(x<=100000) ++tree[x],x+=x&(-x);
	return ;
}
int find(int x)
{
	int res=0;
	while(x) res+=tree[x],x-=x&(-x);
	return res;
}
struct node{int id,k,op;};
vector<node> v[100003];
signed main()
{
	freopen("greatwall.in","r",stdin);
	freopen("greatwall.out","w",stdout);
    int n=read(),m=read();
    for(int i=1; i<=n; i++) lsh[i]=a[i]=read();
    sort(lsh+1,lsh+n+1);
    int len=unique(lsh+1,lsh+n+1)-lsh-1;
    for(int i=1; i<=n; i++) a[i]=lower_bound(lsh+1,lsh+len+1,a[i])-lsh;
    lsh[len+1]=1000000001;
    for(int i=1,l,r,k; i<=m; i++) 
    {
    	l=read()-1,r=read(),k=upper_bound(lsh+1,lsh+len+2,read())-lsh-1;//最大不超过
		v[l].push_back((node){i,k,-1}),v[r].push_back((node){i,k,1});
	}
	for(int i=1; i<=n; i++) 
	{
		add(a[i]);
		for(int j=0;j<v[i].size();j++)ans[v[i][j].id]+=find(v[i][j].k)*v[i][j].op;
	}
    for(int i=1; i<=m; i++) printf("%d ",ans[i]);
    fclose(stdin);
    fclose(stdout);
	return 0;
}
