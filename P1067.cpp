#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int i=n;i>=0;i--)
	{
		int p;
		cin>>p;
		if(i==n)
		{
			if(i!=0&&i!=1)
			{
				if(p==1)
				{
					cout<<"x^"<<i;
					continue;
				}
				if(p==-1)
				{
					cout<<"-x^"<<i;
					continue;
				}
				if(p<0)cout<<"-";
				if(p==0)
				{
					n--;
					continue;
				}
				p=abs(p);
				cout<<p<<"x^"<<i;
			}
			else if(i==0)
			{
				cout<<p;
				continue;
			}
			else cout<<p<<"x";
		}
		else if(i==0)
		{
			if(p>0)cout<<"+";
			if(p==0)continue;
			if(p<0)cout<<"-";
			p=abs(p);
			cout<<p;
		}
		else if(i!=1)
		{
			if(p==0)continue;
			if(p==1)
			{
				cout<<"+";
				goto flag1;
			}
			if(p==-1)
			{
				cout<<"-";
				goto flag1;
			}
			if(p>0)cout<<"+";
			if(p==0)continue;
			if(p<0)cout<<"-";
			p=abs(p);
			cout<<p;
			flag1:
			cout<<"x^"<<i;
		}
		else if(i==1)
		{
			if(p==0)continue;
			if(p>0)cout<<"+";
			if(p!=1&&p!=-1)cout<<p;
			if(p==-1)cout<<"-";
			cout<<"x";
		}
	}
}
