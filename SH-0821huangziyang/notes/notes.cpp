//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=55;
struct Data
{
	int val,cnt;
	bool operator<(Data x)const
	{
		return val>x.val;
	}
}t[N];
int T,n,sum;
priority_queue<Data>q;
signed main()
{
	freopen("notes.in","r",stdin);
	freopen("notes.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;sum=0;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)cin>>t[i].val>>t[i].cnt,q.push(t[i]);
		while(q.size()>=1)
		{
			if(q.size()==1)
			{
				if(q.top().cnt==1)break;
			}
			Data x=q.top();
			q.pop();
			if(x.cnt%2==0)
			{
				sum+=x.cnt*x.val;
				q.push((Data){x.val*2,x.cnt/2});
			}
			else if(x.cnt==1)
			{
				Data y=q.top();
				q.pop();
				sum+=y.val+x.val;
				q.push((Data){x.val+y.val,1});
				y.cnt--;
				if(y.cnt)q.push(y);
			}
			else
			{
				sum+=(--x.cnt)*x.val;
				q.push((Data){x.val*2,x.cnt/2});
				q.push((Data){x.val,1});
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}	
