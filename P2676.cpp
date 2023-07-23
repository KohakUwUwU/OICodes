#include<iostream>
#include<queue>
using namespace std;
int n,m;
priority_queue<int,vector<int> >q;
int main()
{
	cin>>n>>m;
	while(n--)
	{
		int tmp;
		cin>>tmp;
		q.push(tmp);
	}
	int sum=0,cnt=0;
	while(sum<m)cnt++,sum+=q.top(),q.pop();
	cout<<cnt;
}
