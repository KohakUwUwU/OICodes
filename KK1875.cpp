#include<bits/stdc++.h>
#define N 5005
using namespace std;
int r,b;
double rin[N][N];
int main()
{
	freopen("casino.in","r",stdin);
	freopen("casino.out","w",stdout);
	cin>>r>>b;
	for(int i=1;i<=r;i++)
	{
		rin[i][0]=i;
		for(int j=1;j<=b;j++)
		{
			if(rin[i][j-1]==0.0&&rin[i-1][j]==0.0)continue;
			rin[i][j]=(rin[i-1][j]+1)*i/(i+j)+(rin[i][j-1]-1)*j/(i+j);
			rin[i][j]=max((double)0.0,rin[i][j]);
		}
	}
	double ans=double(int(rin[r][b]/0.001))/1000;
	cout<<fixed<<setprecision(3)<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
