#include<iostream>
#include<queue>
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int> >G;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		G.push(c);
	}
	cout<<G.top();
}
