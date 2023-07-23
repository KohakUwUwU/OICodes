#include<iostream>
#include<algorithm>
using namespace std;
struct fsdal
{
	int value,color,pos,data;
}data1[100001],data2[100001];
long long c,v;//??¡Á?¦Ì?¨¬? ?-¨®D¦Ì?¨¬? 
int n,m;
int clb1[100001],clb2[100001];//colorbound(R)
int clnum;//max color
bool cmp(fsdal a,fsdal b)
{
	if(a.color!=b.color)return a.color<b.color;
	else if(a.value!=b.value)return a.value>b.value;
	else return false;
}
bool cmp1(fsdal a,fsdsl b)
{
	if(a.data!=b.data)return 
}
int main()
{
	cin>>n>>m>>c>>v;
	for(int i=1;i<=n;i++)cin>>data1[i].color>>data1[i].value,data1[i].pos=i;
	for(int i=1;i<=m;i++)cin>>data2[i].color>>data2[i].value,data2[i].pos=i;
	sort(data1+1,data1+n+1,cmp);
	sort(data2+1,data2+m+1,cmp);
	int tmp0=1;
	for(int i=1;i<=n;i++)
	{
		if(data1[i].value!=tmp0)
		{
			while(1)
			{
				clb1[tmp0]=i-1;
				tmp0++;
				if(tmp0==data1[i].value)break;
			}
		}
	}
	clnum=max(clnum,tmp0);
	tmp0=1;
	for(int i=1;i<=m;i++)
	{
		if(data2[i].value!=tmp0)
		{
			while(1)
			{
				clb2[tmp0]=i-1;
				tmp0++;
				if(tmp0==data2[i].value)break;
			}
		}
	}
	clnum=max(clnum,tmp0);
	for(int i=1;i<=clnum;i++)
	{
		int j=clb1[i-1]+1,k=clb2[i-1]+1;
		int r1=clb1[i],r2=clb2[i];
		while(j<=r1&&k<=r2)
		{
			while(data1[j].value<data2[k].value&&k+1<=r2)k++;
			while(data1[j].value>=data2[k].value&&j+1<=r1&&k+1<=r2)
			{
				data1[j].data=1;
				data2[k++].data=data1[j].pos;
		    	v+=c+data1[j++].value;
			}
		}
		
	}
	sort(data1+1,data1+1+n,cmp1);
	sort(data2+1,data2+1+m,cmp2);
	
}//1¡ä¨°1y¦Ì?????¦Ì?data=1 2data??¦Ì?????output 

