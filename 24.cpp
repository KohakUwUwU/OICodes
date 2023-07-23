#include<iostream>
using namespace std;
int m[1001][1001];
int main()
{
	int num,money;
	cin>>num>>money;
	for(int i=1;i<=num;i++)
	{
		int p;
		cin>>p;
		m[i][0]=1;
		if(i>1)
		{
			for(int j=0;j<p;j++)m[i][j]=m[i-1][j];
		}
		for(int j=p;j<=money;j++)m[i][j]=m[i-1][j]+m[i][j-p];
	}
	cout<<m[num][money];
}
