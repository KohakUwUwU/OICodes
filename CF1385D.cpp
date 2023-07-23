#include<iostream>
using namespace std;
string str;
inline int dfs(int l,int r,char v)
{
	if(l==r)
	{
		if(v==str[l])return 0;
		else return 1;
	}
	int mid=(l+r)>>1;
	int ln=0,rn=0;
	for(int i=l;i<=mid;i++)
	{
		if(str[i]!=v)ln++;
	}
	for(int i=mid+1;i<=r;i++)
	{
		if(str[i]!=v)rn++;
	}
	return min(rn+dfs(l,mid,v+1),ln+dfs(mid+1,r,v+1));
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int len=0;
		cin>>len>>str;
		cout<<dfs(0,len-1,'a')<<endl;
	}
}
