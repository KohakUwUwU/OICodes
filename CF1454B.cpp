#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int value;
	int pos;
}a[200005];
int bin[200005];
inline bool cmp(node x,node y)
{
	return x.value<y.value;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].value,a[i].pos=i;
		sort(a+1,a+1+n,cmp);
		int cur=-1;
		int ify=0;
		for(int i=1;i<=n;i++)
		{
			int cnt=0;
			while(a[i].value==a[i+1].value)cnt++,i++;
			if(cnt==0)
			{
				ify=1;
				cout<<a[i-cnt].pos<<endl;
				break;
			}
		}
		if(ify==0)cout<<-1<<endl;
	}
}
