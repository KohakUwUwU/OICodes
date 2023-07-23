#include<iostream>
using namespace std;
const int HASHINT=114514;
string st[1001];//Ë³Ðò´æ´¢str 
unsigned int ha[114514];//¹þÏ£ÖµÓ³Éäµ½mapÉÏ 
int existance[1001];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		if(str=="touch")
		{
			string filename;
			cin>>filename;
			int hab=filename[0];
			for(int j=1;j<filename.length();j++)
			{
				hab+=filename[j]*HASHINT;
				hab%=HASHINT;
			}
			if(ha[hab]==0)ha[hab]=i;
			st[i]=filename;
		}
		if(str=="rm")
		{
			string name;
			cin>>name;
			int hab=name[0];
			for(int j=1;j<name.length();j++)
			{
				hab+=name[j]*HASHINT;
				hab%=HASHINT;
			}
			existance[ha[hab]]=1;
			existance[i]=1;
		}
		if(str=="ls")
		{
			existance[i]=1;
			for(int j=1;j<=n;j++)
			{
				if(existance[j]==0)cout<<st[j]<<'\n';
			}
		}
		if(str=="rename")
		{
			existance[i]=1;
			string xxx,yyy;
			cin>>xxx>>yyy;
			int hab=yyy[0];
			for(int j=1;j<yyy.length();j++)
			{
				hab+=yyy[j]*HASHINT;
				hab%=HASHINT;
			}
			if(ha[hab]!=0)continue;
			int haa=xxx[0];
			for(int j=1;j<xxx.length();j++)
			{
				haa+=xxx[j]*HASHINT;
				haa%=HASHINT;
			}
			st[ha[haa]]=yyy;
			ha[hab]=ha[haa];
			ha[haa]=0;
		}
	}
}
