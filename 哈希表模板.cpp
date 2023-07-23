#include<iostream>
#define U unsigned long long
using namespace std;
int n,m,str[10001];
U hash[100][1001];
inline int calc(int a){return a%97;}
inline void insert(int a){hash[calc(a)][++hash[calc(a)][0]]=a;}
inline bool findx(int a,int b){for(int i=1;i<=hash[a][0];i++)if(hash[a][i]==b)return true;return false;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i];
		insert(str[i]);
	}
	int in;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>in;
		if(findx(calc(in),in))cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
