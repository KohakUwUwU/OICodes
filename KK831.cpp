//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
const unsigned int H=114514191981;
string str;
unsigned int P[N],fow[N],baw[N];
inline unsigned int F(int i,int j)
{
	if(i==0)return fow[j];
	return fow[j]-fow[i-1]*P[j-i+1];
}
inline unsigned int B(int i,int j)
{
	return baw[i]-baw[j+1]*P[j-i+1];
}
inline int judge1(int k)
{
	int len=0;
	for(int i=20;i>=0;i--)
	{
		if(k+len+(1<<i)>=str.length()||k-len-(1<<i)<0)continue;
		if(B(k-len-(1<<i),k)==F(k,k+len+(1<<i)))len+=(1<<i);
	}
	return len*2+1;
}
inline int judge2(int k)
{
	if(str[k]!=str[k+1])return 0;
	int len=0;
	for(int i=20;i>=0;i--)
	{
		if(k+1+len+(1<<i)>=str.length()||k-len-(1<<i)<0)continue;
		if(B(k-len-(1<<i),k)==F(k+1,k+1+len+(1<<i)))len+=(1<<i);
	}
	return len*2+2;
}
signed main()
{
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	cin>>str;
	P[0]=1;
	for(int i=1;i<=str.length();i++)P[i]=P[i-1]*H;
	fow[0]=(unsigned int)str[0];
	baw[str.length()-1]=(unsigned int)str[str.length()-1];
	for(int i=1;i<str.length();i++)fow[i]=fow[i-1]*H+(unsigned int)str[i];
	for(int i=str.length()-2;i>=0;i--)baw[i]=baw[i+1]*H+(unsigned int)str[i];
	int ans=-1;
	for(int i=0;i<str.length();i++)ans=max(ans,judge1(i));
	for(int i=0;i<str.length()-1;i++)ans=max(ans,judge2(i));
	cout<<ans;
	return 0;
}

