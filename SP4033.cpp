#include<bits/stdc++.h>
using namespace std;
struct node
{
	bool end;
	int value;
	node* p[11];
	node()
	{
		end=false;
		value=-1;
		memset(p,int(NULL),sizeof(p));
	}
}data[1000001];
int t,n,flag;
string str;
void mems()
{
	for(int i=0;i<=flag;i++)data[i].end=false,data[i].value=-1,memset(data[i].p,int(NULL),sizeof(data[i].p));
}
int main()
{
	cin>>t;
	while(t--)
	{
		bool bb=false;
		mems();
		flag=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			node* po=&data[0];
			for(int j=0;j<str.length();j++)
			{
				int m=str[i]-'0';
				if(po->p[m]==NULL)
				{
					data[++flag].value=m;
					po->p[m]=&data[flag];
				}
				cout<<po<<endl<<flag<<endl;
				po=po->p[m];
				if(po->end==true)bb=true;
				if(j==str.length()-1)po->end=true;
			}
		}
		if(bb==false)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
