#include<iostream>
#include<algorithm>
#define N 200005
using namespace std;
string str[N],cur=" ";
int main()
{
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>str[i];
	sort(str+1,str+1+n);
	for(int i=1;i<=n;i++)if(cur!=str[i])cnt++,cur=str[i];
	cout<<cnt;
}
