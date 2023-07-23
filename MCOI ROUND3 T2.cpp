#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int,int> G,con;//ºÃ¸Ð¶È 
int main()
{
	long long t,n,Max,MAXI,x,y,MAXRUNI,MAXRUN;
	long long m;
	cin>>t;
	while(t--)
	{
		Max=-1;MAXRUN=-1;
		con[0]=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&G[i]);
			if(Max<G[i])
			{
				Max=G[i];
				MAXI=i;
			}
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			int f=0;
			if(x==MAXI)con[++con[0]]=y,f=1;
			if(y==MAXI)con[++con[0]]=x,f=1;
			if(f==1)
			{
				if(G[con[con[0]]]>MAXRUN||G[con[con[0]]]==MAXRUN&&con[con[0]]<MAXRUNI)
				{
					MAXRUN=G[con[con[0]]];
					MAXRUNI=con[con[0]];
				}
			}
		}
		//MAXI MAXRUNI
		int cha=G[MAXI]-G[MAXRUNI];
//		cout<<MAXI<<endl<<MAXRUNI<<endl;
		if(m<cha)
		{
			cout<<MAXI<<endl;
			continue;
		}
		
		if(MAXI<MAXRUNI)swap(MAXI,MAXRUNI);
//		MAXRUNI>MAXI
		if((m-cha)%2==1)cout<<MAXI<<endl;
		else cout<<MAXRUNI<<endl;
//		cout<<min(MAXI,MAXRUNI)<<endl;
	}
}
