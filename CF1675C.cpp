//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

//���ȫ���ʺ�ֻ��һ��1���Ǿ�������
//���ֻ��һ��0���Ǿ���[0,id(0)] 
//�����һ����0���Ǿ��ǵ�һ�� 
//���ȫ��1���Ǿ������һ��
//���ұߵ�1�����ֻҪ��0��Ҳֻ������һ��������һ������ 
//���û����[x,��һ��0]�п��� 
int state[10];
//1:whether all 1? 1->no
//2:the id of the most right 1
//3:the id of the most left 0
//4:the count of number
//5:the id of last number
inline void check(string str)
{
	state[1]=0;
	state[2]=state[3]=-1;
	state[4]=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='0'||str[i]=='1')state[4]++,state[5]=i;
		if(str[i]=='0')state[1]=1;
		if(str[i]=='1')state[2]=i;
		if(str[i]=='0'&&state[3]==-1)state[3]=i;
	}
}
//right1=left0=0
//if right1==left0==0 all
//if right1==0 left0+1
//else if left0==0 str.length()-right1
//else if left0<right1 1
//else left0-right1+1
signed main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		int left0=-1,right1=-1;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='0'&&left0==-1)left0=i;
			if(str[i]=='1')right1=i;
		}
		if(right1==left0&&right1==-1)cout<<str.length()<<'\n';
		else if(right1==-1)cout<<left0+1<<'\n';
		else if(left0==-1)cout<<str.length()-right1<<'\n';
		else if(left0<right1)cout<<1<<'\n';
		else cout<<left0-right1+1<<'\n';
	}
	return 0;
}

