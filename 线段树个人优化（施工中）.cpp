//姐姐好可爱w 
#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],ans[1000003],l[1000003],r[1000003],t[1000003],pos[1000003],val[1000003];
//a:数组前缀和 ans:最终答案 l:询问左端点 r:询问右端点 t:询问时间戳（从0开始）pos:修改位置 val:修改数值 
void query(int L,int R,vector<int>& qid,vector<int>& uid)
//qid代表询问的下标，uid代表修改的下标 
{
	vector<int> lq,lu,rq,ru,nq;
	//下传到左/右边的询问/修改 当前询问/修改 
	int mid=(L+R)>>1;
	for(int x:uid) if(pos[x]<=mid) lu.push_back(x); else ru.push_back(x);
	for(int x:qid)
	{
		if(l[x]<=L&&R<=r[x]) nq.push_back(x);
		//区间全覆盖，这段的值可以都用 
		else
		{
			if(r[x]>mid) rq.push_back(x);
			if(l[x]<=mid) lq.push_back(x);
			//对应下传 
		}
	}
	int pos=0,sum=0;
	//sum为在第uid[pos]次操作前所有对[L,R]中元素修改的操作的总值 
	for(int x:nq)
	{
		while(pos<(int)uid.size()&&uid[pos]<=t[x]) sum+=val[uid[pos++]];
		ans[x]+=sum; 
	}
	if(L==R) return ;
	if(lq.size()&&lu.size()) query(L,mid,lq,lu);
	if(rq.size()&&ru.size())query(mid+1,R,rq,ru);
}
signed main()
{
	//freopen("P3374_2.in","r",stdin);
	vector<int> uid,qid;
	int n=read(),m=read(),cntq=0,cntu=0;
	for(int i=1; i<=n; i++) a[i]=read()+a[i-1];
	for(int x,y,z; m--;)
	{
		x=read(),y=read(),z=read();
		if(x==1) uid.push_back(++cntu),pos[cntu]=y,val[cntu]=z;
		else qid.push_back(++cntq),l[cntq]=y,r[cntq]=z,ans[cntq]=a[z]-a[y-1],t[cntq]=cntu;
	}
	query(1,n,qid,uid);
	for(int i=1; i<=cntq; i++) printf("%lld\n",ans[i]);
	return 0;
}

