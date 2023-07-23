#include<bits/stdc++.h>
using namespace std;
map<int,int>f;
int main()
{
	int m,n=1;
	cin>>m;
	f[0]=1;f[1]=1;
	while(f[0]%m!=0||f[1]%m!=1)f[2]=(f[0]+f[1])%m,f[0]=f[1],f[1]=f[2],n++;
	cout<<n;
}
