#include<iostream>
#include<cstring>
#include<iomanip>
#include<windows.h>
#include<cstdio> 
using namespace std;
char map[51][51];
char mapinput[3]={'.','B','W'};
char input1;
int x,y;
inline void print()
{
	system("cls");
	printf("  ");
	for(int i=1;i<=20;i++)printf("%2d",i);
	printf("\n");
	for(int i=1;i<=20;i++)
	{
		printf("%2d",i);
		for(int j=1;j<=20;j++)printf("%2c",map[i][j]);
		printf("\n");
	}
}
inline int judge()
{
	bool if0ornot=false;
	for(int i=1;i<=20;i++)
	{
		char t=map[i][1];
		int ans=1;
		for(int j=2;j<=20;j++)
		{
			if(map[i][j]=='.')if0ornot=true;
			if(t==map[i][j])ans++;
			else{
				t=map[i][j];
				ans=1;
			}
			if(ans==5&&t!='.')return 1;
		}
	}
	for(int i=1;i<=20;i++)
	{
		char t=map[1][i];
		int ans=1;
		for(int j=2;j<=20;j++)
		{
			if(t==map[j][i])ans++;
			else{
				t=map[j][i];
				ans=1;
			}
			if(ans==5&&t!='.')return 1;
		}
	}
	for(int i=5;i<=20;i++)
	{
		char t=map[i][1];
		int ans=1;
		for(int j=2;j<=i;j++)
		{
			if(t==map[i-j+1][j])ans++;
			else{
				t=map[i-j+1][j];
				ans=1;
			}
			if(ans==5&&t!='.')return 1;
		}
		t=map[20][20-i+1];
		ans=1;
		for(int j=2;j<=i;j++)
		{
			if(t==map[20-j+1][20-i+j])ans++;
			else{
				t=map[20-j+1][20-i+j];
				ans=1;
			}
			if(ans==5&&t!='.')return 1;
		}
	}
	for(int i=5;i<=20;i++)
	{
		char t=map[20-i+1][1];
		int ans=1;
		for(int j=2;j<=i;j++)
		{
			if(t==map[20-i+j][j])ans++;
			else{
				t=map[20-i+j][j];
				ans=1;
			}
			if(ans==5&&t!='.')return 1;
		}
		t=map[1][20-i+1];
		ans=1;
		for(int j=2;j<=i;j++)
		{
			if(t==map[j][20-i+j])ans++;
			else{
				t=map[j][20-i+j];
				ans=1;
			}
			if(ans==5&&t!='.')return 1;
		}
	}
	if(if0ornot==false)return 0;
	else return 2;
}
int main()
{
	while(1)
	{
		memset(map,'.',sizeof(map));
		printf("Input Z to exit. Press any key except Z to enter the game.\n");
		scanf("%c",&input1);
		if(input1=='Z')break;
		while(1)
		{
			int tmp=-1;
			for(int i=1;i<=2;i++)
			{
				print();
				tiaozhuan:;
				printf("%c turn\nInput position:",mapinput[i]);
				cin>>x>>y;
				if(map[x][y]!='.'||x<=0||y<=0||x>20||y>20)
				{
					cout<<"Invalid position! Please enter again.\n";
					goto tiaozhuan;
				}
				map[x][y]=mapinput[i];
				tmp=judge();
				if(tmp==0)
				{
					printf("Tie.\n");
					break;
				}
				else if(tmp==1)
				{
					if(i==1)printf("Black win.\n");
					else printf("White win.\n");
					break;
				}
			}
			if(tmp==1||tmp==0){
				printf("Enter any key to continue.\n");
				getchar();
				break;
			}
		}
	}
	printf("Enter any key to exit...\n");
	getchar();
	return 0;
}
