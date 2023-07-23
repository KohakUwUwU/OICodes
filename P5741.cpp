#include<iostream>
#include<cmath>
using namespace std;
struct stu
{
	string name;
	int a,b,c,sum;
	void op()
	{
		sum=a+b+c;
	}
}d[10001];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i].name>>d[i].a>>d[i].b>>d[i].c,d[i].op();
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
	{
		if(abs(d[i].a-d[j].a)<=5&&abs(d[i].b-d[j].b)<=5&&abs(d[i].c-d[j].c)<=5&&abs(d[i].sum-d[j].sum)<=10)cout<<d[i].name<<" "<<d[j].name<<endl;
	}
}
