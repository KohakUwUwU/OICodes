//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int a[1005],b,lis[N],d[N],la,lb,llis;
vector<int>pos[N];
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	string str1,str2;
    cin>>str1>>str2;
    la=str1.length();lb=str2.length();
    for(int i=1;i<=la;i++)a[i]=str1[i-1];
    for(int i=1;i<=lb;i++)pos[str2[i-1]+3124].push_back(i);
    for(int i=0;i<=la;i++)for(int j=pos[a[i]+3124].size()-1;j>=0;j--)lis[llis++]=pos[a[i]+3124][j];
    d[1]=lis[1];
    int mll=1;
    for(int i=2;i<=llis;i++)
    {
    	if(lis[i]>d[mll])d[++mll]=lis[i];
    	else d[lower_bound(d,d+mll,lis[i])-d]=lis[i];
	}
	cout<<mll;
    return 0;
}
