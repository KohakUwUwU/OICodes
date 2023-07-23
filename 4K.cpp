//Don't Fight The Music
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define int long long
using namespace std;

int a[25],pb=0;
signed main()
{
	while(1)
	{
		cout<<"游戏规则：\n";
		cout<<"游戏中的四个轨道分别对应DFJK四个按键"<<'\n';
		cout<<"看准按键按下去吧！限时1分钟！(人工喊停)按错了游戏就会结束哦！\n"; 
		cout<<"目前最佳成绩为："<<pb<<'\n';
		cout<<"按回车开始游戏..."<<'\n';
		char c=getchar(); 
		system("cls");
		cout<<"游戏准备开始！"<<'\n';
		_sleep(1000);
		cout<<"3!\n";
		_sleep(1000);
		cout<<"2!\n";
		_sleep(1000);
		cout<<"1!\n";
		srand((int)(time(0)));
		for(int i=1;i<=20;i++)a[i]=rand()%4+1;
		int combo=0;
		while(1)
		{
			system("cls");
			cout<<"COMBO="<<combo<<'\n';
			for(int i=20;i>=1;i--)
			{
				if(a[i]==1)cout<<"0\n";
				else if(a[i]==2)cout<<"  0\n";
				else if(a[i]==3)cout<<"    0\n";
				else cout<<"      0\n";
			}
			cout<<"D F J K\n";
			int ch=_getch();
			int should;
			if(a[1]==1)should=100;
			else if(a[1]==2)should=102;
			else if(a[1]==3)should=106;
			else should=107;
			if(ch!=should)
			{
				cout<<"游戏结束！你的游戏成绩是:"<<combo<<'\n'; 
				_sleep(5000);
				break; 
			}
			combo++;
			for(int i=1;i<=19;i++)a[i]=a[i+1];
			a[20]=rand()%4+1;
		}
		system("cls");
	}
	return 0;
}

