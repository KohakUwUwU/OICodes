#include<bits/stdc++.h>
#define int long long
#define N 60
using namespace std;
int n,m,t,in;
int kkksc03[N][2];//���� 
int RinChan[N][N][3];//�����彴�� //��¼��̬�滮ǰ׺��
int MikuSan[N*N];//����MIKU�� //���� 
string str;
signed main()
{
//	n=read();m=read();t=read();
//	cin>>n>>m>>t;
	scanf("%ld%ld%ld",&n,&m,&t);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)scanf("%1ld",&in),kkksc03[j][in]=kkksc03[j-1][in]+1,kkksc03[j][in^1]=kkksc03[j-1][in^1];
		//��ү����ҪTLE 
		for(int j=1;j<=m;j++)for(int k=0;k<j;k++)for(int l=1;l<=j;l++)for(int b=0;b<=1;b++)RinChan[j][l][b]=max(RinChan[k][l][b],RinChan[k][l-1][b^1])+kkksc03[j][b]-kkksc03[k][b];
		for(int j=1;j<=min(m,j);j++)RinChan[m][j][2]=max(RinChan[m][j][0],RinChan[m][j][1]);
		for(int j=t;j>0;j--)for(int k=1;k<=min(m,j);k++)MikuSan[j]=max(MikuSan[j],MikuSan[j-k]+RinChan[m][j][2]);
	}
	cout<<MikuSan[t];
}//ϣ����ҪTLE 
