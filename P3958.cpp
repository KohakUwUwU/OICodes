#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
int timee;
long long t,n,h,r;
struct hole
{
	int x,y,z;
}ho[1001];
int g[1001][1001];
int bottom[1001];
map<int,int>top;
//qwq
int head=0,tail=1;
struct node
{
	int x;
}q[100001];
int vis[10001];

inline double dist(int a1,int a2)
{
//	cout<<a1<<" "<<a2<<":"<<ho[a1].x<<" "<<ho[a1].y<<" "<<ho[a1].z<<" "<<ho[a2].x<<" "<<ho[a2].y<<" "<<ho[a2].z<<endl;
	return sqrt((ho[a1].x-ho[a2].x)*(ho[a1].x-ho[a2].x)+(ho[a1].y-ho[a2].y)*(ho[a1].y-ho[a2].y)+(ho[a1].z-ho[a2].z)*(ho[a1].z-ho[a2].z));
}//���� 
int main()
{
	cin>>timee;
	while(timee--)
	{
		int tmp3=0;
		cin>>n>>h>>r;
		for(int i=1;i<=n;i++)
		{
			int tmp1=0,tmp2=0;
			cin>>ho[i].x>>ho[i].y>>ho[i].z;
			if(ho[i].z-r<=0)bottom[++bottom[0]]=i,tmp1=1;
			if(ho[i].z+r>=h)top[i]=1,tmp2=1;
			if(tmp1==1&&tmp2==1)tmp3=1;
		}
		if(tmp3==1)
		{
			cout<<"Yes"<<endl;
			continue;
		}
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				register double vocal=dist(i,j);
				register double loid=2.0*r;
				if(vocal<=loid)g[i][j]=g[j][i]=1;
//				cout<<"g"<<i<<" "<<j<<" "<<vocal<<endl;
			}
		}
		for(int i=1;i<=bottom[0];i++)
		{
			head=0,tail=1;
			memset(q,0,sizeof(q));
			memset(vis,0,sizeof(vis));
			q[head].x=bottom[i];
			vis[bottom[i]]=1;
			while(head<tail)
			{
				for(int j=1;j<=n;j++)
				{
					if(g[q[head].x][j]==1&&vis[j]==0)
					{
					    vis[j]=1;
					    q[tail].x=j;
					    if(top[q[tail].x]==1)
					    {
					    	cout<<"Yes"<<endl;
//					    	tmptmp=1;
					    	goto flag;
					    }
					    tail++;
					}
				}
				head++;
			}
		}
		cout<<"No"<<endl;
		flag:;
	}
}

