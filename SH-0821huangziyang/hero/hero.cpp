//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Data
{
	int val,cnt;
};
int n,r,c;
int p,cur,ans=-114514114514;//当前已经到第几行,第几列 
vector<Data>a[3];
inline void Clear()
{
	a[(++p)%3].clear();
	cur=0;
}
inline void print()
{
	for(int i=0;i<a[(p+2)%3].size();i++)cout<<a[(p+2)%3][i].val<<','<<a[(p+2)%3][i].cnt<<' ';
	cout<<'\n';
	for(int i=0;i<a[p%3].size();i++)cout<<a[p%3][i].val<<','<<a[p%3][i].cnt<<' ';
	cout<<'\n';
}
int u[1001],d;
inline void calc()
{
	if(p==0)return ;
//	print();
	memset(u,0,sizeof(u));
	d=0;
	int p1=0,p2=0,last1=0,last2=0;
	int k=(p+2)%3,l=p%3;
	while(p1<a[k].size()&&p2<a[l].size())
	{
		if(last1==0&&last2==0)
		{
//			cout<<"% ";
			if(a[k][p1].cnt==a[l][p2].cnt)u[++d]=a[k][p1].cnt*(a[k][p1].val+a[l][p2].val),p1++,p2++;
			else if(a[k][p1].cnt<a[l][p2].cnt)
			{
				u[++d]=a[k][p1].cnt*(a[k][p1].val+a[l][p2].val);
				last2=a[l][p2].cnt-a[k][p1].cnt;
				p1++;
			}
			else
			{
				u[++d]=a[l][p2].cnt*(a[k][p1].val+a[l][p2].val);
				last1=a[k][p1].cnt-a[l][p2].cnt;
				p2++;
			}
			continue;
		}
		else if(last1)
		{
//			cout<<"%% ";
			if(a[l][p2].cnt==last1)last1=0,u[++d]=a[l][p2].cnt*(a[k][p1].val+a[l][p2].val),p1++,p2++;
			else if(a[l][p2].cnt<last1)
			{
				last1-=a[l][p2].cnt;
//				cout<<a[l][p2].cnt<<' '<<a[k][p1].val+a[l][p2].val<<'\n';
				u[++d]=a[l][p2].cnt*(a[k][p1].val+a[l][p2].val),p2++;
			}
			else
			{
				u[++d]=last1*(a[k][p1].val+a[l][p2].val);
				last2=a[l][p2].cnt-last1;
				last1=0;
				p1++;
			}
			continue;
		}
		else
		{
//			cout<<"%%% ";
			if(a[k][p1].cnt==last2)last2=0,u[++d]=a[k][p1].cnt*(a[k][p1].val+a[l][p2].val),p1++,p2++;
			else if(a[k][p1].cnt<last2)
			{
				last2-=a[k][p1].cnt;
				u[++d]=a[k][p1].cnt*(a[k][p1].val+a[l][p2].val),p1++;
			}
			else
			{
				u[++d]=last2*(a[k][p1].val+a[l][p2].val);
				last1=a[k][p1].cnt-last2;
				last2=0;
				p2++;
			}
			continue;
		}
	}
//	for(int i=1;i<=d;i++)cout<<u[i]<<' ';
//	cout<<'\n';
	int sum=-114514114514;
	int b=0;
	for(int i=1;i<=d;i++)
	{
		if(b>0)b+=u[i];
		else b=u[i];
		if(b>sum)sum=b;
	}
//	cout<<sum<<'\n';
	ans=max(ans,sum);
}
signed main()
{
	freopen("hero.in","r",stdin);
	freopen("hero.out","w",stdout);
	cin>>n>>r>>c;
	for(int i=1;i<=n;i++)
	{
		Data x;
		cin>>x.val>>x.cnt;
		if(x.cnt+cur<c)a[p%3].push_back(x),cur+=x.cnt;
		else if(x.cnt+cur==c)a[p%3].push_back(x),calc(),Clear();
		else
		{
			a[p%3].push_back((Data){x.val,c-cur});
			calc();
			x.cnt-=c-cur;
			Clear();
			if(x.cnt<c)a[p%3].push_back(x),cur+=x.cnt;
			else if(x.cnt==c)a[p%3].push_back(x),calc(),Clear();
			else if(c<x.cnt&&x.cnt<2*c)
			{
				a[p%3].push_back((Data){x.val,c});
				calc();
				Clear();
				x.cnt-=c;
				a[p%3].push_back(x);
				cur+=x.cnt;
			}
			else if(x.cnt==2*c)
			{
				a[p%3].push_back((Data){x.val,c});
				calc();
				Clear();
				a[p%3].push_back((Data){x.val,c});
				calc();
				Clear();
			}
			else
			{
				if(x.val<0)ans=max(ans,2*x.val);
				else ans=max(ans,2*c*x.val);
				a[p%3].push_back((Data){x.val,c});
				calc();
				Clear();
				a[p%3].push_back((Data){x.val,(x.cnt%c==0)?(c):(x.cnt%c)});
				if(x.cnt%c==0)Clear();
				cur=x.cnt%c;
			}
		}
	}
	cout<<ans;
	return 0;
}

