#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline string mul(string a,int b)
{
    const int L=100005;
    int na[L];
    string ans;
    int La=a.size();
    fill(na,na+L,0);
    for(int i=La-1;i>=0;i--) na[La-i-1]=a[i]-'0';
    int w=0;
    for(int i=0;i<La;i++) na[i]=na[i]*b+w,w=na[i]/10,na[i]=na[i]%10;
    while(w) na[La++]=w%10,w/=10;
    La--;
    while(La>=0) ans+=na[La--]+'0';
    return ans;
}
inline string add(string a,string b)
{
    const int L=1e5;
    string ans;
    int na[L]={0},nb[L]={0};
    int la=a.size(),lb=b.size();
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    int lmax=la>lb?la:lb;
    for(int i=0;i<lmax;i++) na[i]+=nb[i],na[i+1]+=na[i]/10,na[i]%=10;
    if(na[lmax]) lmax++;
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    return ans;
}
string f[503][512],g[503][512];
//前i位，状态为j的方案数和答案
int s[13];
//如果已经选了s[i]，就不能选i了
const string Digits[]={"1","2","3","4","5","6","7","8","9"};
signed main()
{
	freopen("word.in","r",stdin);freopen("word.out","w",stdout);
	int n=read(),m=read(),k=read(),tot=1<<k;
	for(int i=1,x,y; i<=m; ++i) x=read()-1,y=read()-1,s[y]|=(1<<x);
	for(int i=1; i<=n; ++i) for(int j=1; j<tot; ++j) f[i][j]=g[i][j]="0";
	for(int i=0; i<k; ++i) f[1][1<<i]="1",g[1][1<<i]=Digits[i];
	for(int i=1; i<n; ++i) for(int j=0; j<tot; ++j) for(int t=0; t<k; ++t) if((j&s[t])==0) 
	f[i+1][j|(1<<t)]=add(f[i+1][j|(1<<t)],f[i][j]),
	g[i+1][j|(1<<t)]=add(g[i+1][j|(1<<t)],add(g[i][j]+"0",mul(f[i][j],t+1)));
	string ans1="0",ans2="0";
	for(int i=0; i<tot; ++i) ans1=add(ans1,f[n][i]),ans2=add(ans2,g[n][i]);
	cout<<ans1<<endl<<ans2<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}

