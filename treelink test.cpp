#include<iostream>
using namespace std;
string str;
int con[1001],Log[1001];
int n,q;
inline int getInt(int st,int ed)
{
	int s;
	for(int i=st;i<=ed;i++)s=s*10+str[i]-'0';
	return s;
}
//inline void opLCA()
//{
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=20;j++)cout<<lca[i][j]<<' ';
//		cout<<'\n';
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=20;j++)cout<<lti[i][j]<<' ';
//		cout<<'\n';
//	}
//}
inline void loging()
{
	Log[0]=-1;
	for(int i=1;i<=n;i++)Log[i]=Log[i/2]+1;
}
int main()
{
	cin>>n;
	loging();
	for(int i=1;i<=n;i++)cout<<Log[i]<<" ";
}
