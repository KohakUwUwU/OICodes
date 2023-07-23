#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch ��������ʱ
    if (ch == '-') w = -1;        // �ж��Ƿ�Ϊ��
    ch = getchar();               // ��������
  }
  while (ch >= '0' && ch <= '9') {  // ch ������ʱ
    x = x * 10 + (ch - '0');  // ���¶�������֡��ӡ��� x �ĺ���
    // x �� int ���ͣ�char ���͵� ch �� ��0�� �ᱻ�Զ�תΪ���Ӧ��
    // ASCII �룬�൱�ڽ� ch ת��Ϊ��Ӧ����
    // �˴�Ҳ����ʹ�� (x<<3)+(x<<1) ��д�������� x*10
    ch = getchar();  // ��������
  }
  return x * w;  // ���� * ������ = ʵ����ֵ
}

const int N=10,mod=1e9+7;
int n,m;
class Matrix
{
	public:
		int r,c,data[N][N];
		Matrix(int _r,int _c)
		{
			r=_r,c=_c;
			memset(data,0,sizeof(data));
		}
		Matrix operator*(const Matrix m)const
		{
			Matrix ans(r,m.c);
			for(int i=0;i<r;i++)
				for(int j=0;j<m.c;j++)
					for(int k=0;k<c;k++)
						ans.data[i][j]+=data[i][k]*m.data[k][j],ans.data[i][j]%=mod;
			return ans;
						
		}
		Matrix operator^(int p)const
		{
			Matrix ans(r,r),x=*this;
			for(int i=0;i<r;i++)ans.data[i][i]=1;
			while(p)
			{
				if(p&1)ans=ans*x;
				p>>=1,x=x*x;
			}
			return ans;
		}
};
inline long long gcd(long long a,long long b) {
    while(b^=a^=b^=a%=b);
    return a;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();
	n=gcd(n,m);
	Matrix F(2,1);
	F.data[0][0]=F.data[1][0]=1;
	Matrix p(2,2);
	if(n<=1)
	{
		cout<<1;
		return 0;
	}
	p.data[0][0]=1;p.data[0][1]=1;
	p.data[1][0]=1;p.data[1][1]=0;
	Matrix ans=(p^(n-1))*F;
	cout<<ans.data[0][0];
	return 0;
}

