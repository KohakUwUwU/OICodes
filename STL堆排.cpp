#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int > >q;
int main() {
	register int n,in;
	cin>>n;
	while(n--)cin>>in,q.push(in);
	while(!q.empty())cout<<q.top()<<" ",q.pop();
    return 0;
}
