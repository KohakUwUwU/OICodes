#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
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

