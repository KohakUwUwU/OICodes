#include<bits/stdc++.h>
using namespace std;
int n,t;
struct tt
{
	bool b;
	int value;
	tt* p[10];
	tt()
	{
		b=false;
		value=-1;
		memset(p,int(NULL),sizeof(p));
	}
	void Set()
	{
		b=false;
		value=-1;
		memset(p,int(NULL),sizeof(p));
	}
}trie[100001];
int flag=0;
string str;
inline void Clear()
{
	for(int i=0;i<=flag;i++)trie[i].Set();
	flag=0;
}
inline bool search(tt* po,int state)
{
	bool theend=false;
	if(po->b==true)state++;
	if(state==2)return true;
	for(int i=0;i<10;i++)
	{
		if(po->p[i]!=NULL)if(search(po->p[i],state))
		{
			theend=true;
			break;
		}
	}
	if(theend==true)return true;
	else return false;
}
int main()
{
	cin>>t;
	while(t--)
	{
		Clear();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>str;
			int len=str.length();
			tt* pointer=&trie[0];
			for(int j=0;j<len;j++)
			{
				int m=str[j]-'0';
				if(pointer->p[m]==NULL)
				{
					trie[++flag].value=m;
					pointer->p[m]=&trie[flag];
				}
				pointer=pointer->p[m];
				if(j==len-1)pointer->b=true;
			}
		}
		if(search(&trie[0],0))cout<<"NO";
		else cout<<"YES";
	}
}
