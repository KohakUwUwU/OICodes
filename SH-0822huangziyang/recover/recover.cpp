//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
#define ui unsigned long long
using namespace std;

const int N=1e5+5;
const int HASH=114514191981;
int shoot[130],rvs[130],n;
ui hapow[N*2];
ui hvm[N],hvo[N];
string mi,ori,ori1;
inline void INIT()
{
	ori=mi='0'+ori1;
	n=mi.length()-1;
	for(int i=1;i<=n;i++)mi[i]=shoot[mi[i]];
	//ori前面比mi后面
	hapow[0]=1;
	for(int i=1;i<=114514;i++)hapow[i]=hapow[i-1]*HASH;
	for(int i=1;i<=n;i++)hvm[i]=hvm[i-1]+mi[i]*hapow[i],hvo[i]=hvo[i-1]+ori[i]*hapow[i];
}
inline bool check(int i)
{
	int len=n-i+1;
	if(hvo[len]*hapow[n-len]==hvm[n]-hvm[n-len])return true;
	return false;
}
signed main()
{
	freopen("recover.in","r",stdin);
	freopen("recover.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++)shoot[i+'a']=str[i],rvs[str[i]]=i+'a';
	cin>>ori1;
	INIT();
	for(int i=ceil((double)n/2.0);i<=n;i++)
	{
		if(check(i))
		{
			for(int j=1;j<i;j++)cout<<ori[j];
			for(int j=1;j<i;j++)cout<<(char)rvs[ori[j]];
		}
	}
	return 0;
}

