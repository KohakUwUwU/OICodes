#include<bits/stdc++.h>
#define N (int)1e5+5
using namespace std;
struct node
{
	int l,r,p,ans;
}f[N];
struct Stack
{
	int val[N],head;
	void pop()
	{
		head--;
	}
	int top()
	{
		return val[head-1];
	}
	void push(int x)
	{
		val[head++]=x;
	}
	bool empty()
	{
		return !head;
	}
}st;
int n,q,a[N],sz,bin[N];
inline bool cmp(node x,node y)
{
	return x.l/sz!=y.l/sz?x.l<y.l:((x.l/sz&1)?x.r>y.r:x.r<y.r);
}
inline bool cmpP(node x,node y)
{
	return x.p<y.p;
}
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline void work()
{
	int l=1,r=0;
	for(int i=1;i<=q;i++)
	{
		while(f[i].l>l)
		{
			bin[a[l]]--;
			if(bin[a[l]]>1)st.push(a[l]);
			l++;
		}
		while(f[i].r<r)
		{
			bin[a[r]]--;
			if(bin[a[r]]>1)st.push(a[r]);
			r--;
		}
		while(f[i].l<l)
		{
			l--;
			bin[a[l]]++;
			if(bin[a[l]]>1)st.push(a[l]);
		}
		while(f[i].r>r)
		{
			r++;
			bin[a[r]]++;
			if(bin[a[r]]>1)st.push(a[r]);
		}
		while(!st.empty())
		{
			if(bin[st.top()]>1)
			{
				f[i].ans=1;
				break;
			}
			st.pop();
		}
	}
}
int main()
{
	n=read();q=read();sz=sqrt(n);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=q;i++)f[i].l=read(),f[i].r=read(),f[i].p=i;
	sort(f+1,f+1+q,cmp);
	work();
	sort(f+1,f+1+q,cmpP);
	for(int i=1;i<=q;i++)cout<<(f[i].ans==1?"No":"Yes")<<'\n';
}
