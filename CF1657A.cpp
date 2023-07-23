//LizPlum
#include<bits/stdc++.h>
using namespace std;

int t;
unordered_map<int,int>ma;
int cnt,dx[200],dy[200];
const int INF=11451411;
unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int> > > >f;
inline void Pre()
{
	for(int i=1;i<=300;i++)ma[i*i]=1;
	for(int i=1;i<=50;i++)
	{
		for(int j=1;j<=50;j++)
		{
			if(__gcd(i,j)!=1)continue;
			if(ma[i*i+j*j]!=1)continue;
			++cnt;
			dx[cnt]=i;
			dy[cnt]=j;
		}
	}
}
inline void Floyd()
{
	for(int i=-50;i<=50;i++)for(int j=-50;j<=50;j++)for(int k=-50;k<=50;k++)for(int l=-50;l<=50;l++)f[i][j][k][l]=INF;
	for(int i=0;i<=50;i++)for(int j=0;j<=50;j++)f[i][j][i][j]=0;
	for(int k=1;k<=cnt;k++)
	{
		for(int k_swap=0;k_swap<=1;k_swap++)
		{
			for(int k_x=0;k_x<=1;k_x++)
			{
				for(int k_y=0;k_y<=1;k_y++)
				{
					for(int i=-50;i<=50;i++)
					{
						for(int j=-50;j<=50;j++)
						{
							int dex=dx[k];
							int dey=dy[k];
							if(k_x)dex=-dex;
							if(k_y)dey=-dey;
							if(k_swap)swap(dex,dey);
							int ii=i+dex;
							int jj=j+dey;
//							if(ii<0||jj<0||ii>50||jj>50)continue;
							f[i][j][ii][jj]=f[ii][jj][i][j]=1;
						}
					}
				}
			}
		}
	}
	for(int k=1;k<=cnt;k++)//第几个枚举 
	{
		for(int k_swap=0;k_swap<=1;k_swap++)//交换？ 
		{
			for(int k_x=0;k_x<=1;k_x++)//x是否为负？ 
			{
				for(int k_y=0;k_y<=1;k_y++)//y是否为负？ 
				{
					for(int ix=-50;ix<=50;ix++)
					{
						for(int iy=-50;iy<=50;iy++)
						{
							for(int jx=-50;jx<=50;jx++)
							{
								for(int jy=-50;jy<=50;jy++)
								{
									int delx=dx[k],dely=dy[k];
									if(k_x)delx=-delx;
									if(k_y)dely=-dely;
									if(k_swap)swap(delx,dely);
									int middlex=ix+delx;
									int middley=iy+dely;
//									if(middlex>50||middlex<0||middley>50||middley<0)continue;
									if(ma[(jx-middlex)*(jx-middlex)+(jy-middley)*(jy-middley)]==1)f[ix][iy][jx][jy]=min(f[ix][iy][jx][jy],1+f[middlex][middley][jx][jy]); 
								}
							}
						}
					}
				}
			}
		}
	}
}
signed main()
{
	Pre();
	cout<<"Finish1"<<'\n';
	cout<<"cnt="<<cnt<<'\n';
	Floyd();
	cout<<"Finish2"<<'\n';
	freopen("CF1657.out","w",stdout);
	for(int i=0;i<=50;i++)for(int j=0;j<=50;j++)
	{
		cout<<f[0][0][i][j]<<',';
	}
	return 0;
}
