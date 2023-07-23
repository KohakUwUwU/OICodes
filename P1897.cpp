#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >G;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		G.push(tmp);
	}
	int cur=0;
	long long sum=0;
	while(!G.empty())
	{
		if(G.top()!=cur)
		{
			sum+=(G.top()-cur)*6;
			sum+=5;
			cur=G.top();
		}
		G.pop();
	}
	cout<<cur*4+sum+n;
}
