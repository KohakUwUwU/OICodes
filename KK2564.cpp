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

string s;
signed main()
{
	cin>>s;
	int n=s.length()-1,ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[i]!=s[j])continue;
			int len=0;
			while(s[i+len]==s[j+len]&&j+len<=n)len++;
			len--;
			int r1=i+len,r2=j+len;
			ans+=(n-i+1+n-j+1)*(len+1);
		}
	}
	cout<<ans;
	return 0;
}

