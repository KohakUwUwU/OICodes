#include<bits/stdc++.h>
using namespace std;
struct yyy
{
	string s;
	int n,y,r,num;
}a[110];
int n;
bool cmp(yyy a,yyy b)
{
	if(a.n<b.n)return 1;
	if(a.n>b.n)return 0;
	if(a.n==b.n)
	{
		if(a.y<b.y)return 1;
		if(a.y>b.y)return 0;
		if(a.y==b.y)
		{
			if(a.r<b.r)return 1;
			if(a.r>b.r)return 0;
			if(a.r==b.r)
			{
				if(a.num>b.num)return 1;
				else return 0;
			}
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].s>>a[i].n>>a[i].y>>a[i].r,a[i].num=i;// ‰»Î
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<a[i].s<<endl;
	return 0;
}
