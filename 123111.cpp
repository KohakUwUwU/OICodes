#include<bits/stdc++.h>
#include<windows.h>
#define int long long
using namespace std;

//ģ��⣺��������������ģ������Լ�д 
//���㣺ģ���֧����չ�������Ƽ���������ģ��
//�������루��������ڣ����ڣ� 
const int N=1e5+5;
struct Dot3
{
	double x,y,z;
};
struct Object
{
	string type;//���� 
	Dot3 pos;//���� 
	double sz1,sz2,sz3;
	//cube:a,b,c
	//sphere:r
	//cylinder:h,r1,r2
	double rotate;
}obj[N];
struct Bridge
{
	int exitCnt;//����ڸ���
	vector<pair<Dot3,Dot3> >exit;//�������Ϣ 
	int type;//�������� 
	void print()
	{
		cout<<"exitCnt="<<exitCnt<<'\n';
		for(int i=0;i<exit.size();i++)cout<<exit[i].first.x<<' '<<exit[i].first.y<<' '<<exit[i].first.z<<' '<<exit[i].second.x<<' '<<exit[i].second.y<<' '<<exit[i].second.z<<'\n';
		cout<<"type="<<type<<'\n';
	}
}bri[N];
int objectCnt,bridgeCnt;
inline string toLow(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='A'&&str[i]<='Z')str[i]=str[i]-'A'+'a';
	}
	return str;
}
inline void Notice()
{
	 cout<<"��ʾ:\n";
	 cout<<"1. ��������Ϊ��λ�����κγ���ֵ.\n";
	 cout<<"2. cylinder��centerĬ��Ϊtrue.\n";
	 cout<<"3. �뵥���ŵĳ���ڿ�ȱ���һ��"; 
	cout<<'\n';
}
inline void Input()
{
	cout<<"�����뽨�����������:";
	cin>>objectCnt;
	for(int i=1;i<=objectCnt;i++)
	{
		cout<<"��������������:";
		string str;
		cin>>str;
		str=toLow(str);
		obj[i].type=str;
		if(str=="cube")
		{
			cout<<"��������������:";
			cin>>obj[i].pos.x>>obj[i].pos.y>>obj[i].pos.z; 
			cout<<"������������״����:";
			cin>>obj[i].sz1>>obj[i].sz2>>obj[i].sz3;
			cout<<"������������ת�Ƕ�:";
			cin>>obj[i].rotate;
			if(i!=objectCnt)cout<<"������ϣ���������һ�����壡\n"; 
		}
		else if(str=="sphere")
		{
			cout<<"��������������:";
			cin>>obj[i].pos.x>>obj[i].pos.y>>obj[i].pos.z; 
			cout<<"������������״����:";
			cin>>obj[i].sz1;
			cout<<"������������ת�Ƕ�:";
			cin>>obj[i].rotate;
			if(i!=objectCnt)cout<<"������ϣ���������һ�����壡\n"; 
		}
		else if(str=="cylinder")
		{
			cout<<"��������������:";
			cin>>obj[i].pos.x>>obj[i].pos.y>>obj[i].pos.z; 
			cout<<"������������״����:";
			cin>>obj[i].sz1>>obj[i].sz2>>obj[i].sz3;
			cout<<"������������ת�Ƕ�:";
			cin>>obj[i].rotate;
			if(i!=objectCnt)cout<<"������ϣ���������һ�����壡\n"; 
		}
		else
		{
			cout<<"�Ƿ����ͣ����������룡\n";
			i--;
		}
	}
	cout<<"����������ϣ������������������������\n";
	cout<<"��������������:";
	cin>>bridgeCnt;
	for(int i=1;i<=bridgeCnt;i++)
	{
		cout<<"���������������:";
		cin>>bri[i].exitCnt;
		cout<<"������"<<bri[i].exitCnt<<"����ÿ������������ά��������������\n"; 
		for(int j=0;j<bri[i].exitCnt;j++)
		{
			pair<Dot3,Dot3>d;
			cin>>d.first.x>>d.first.y>>d.first.z;
			cin>>d.second.x>>d.second.y>>d.second.z;
			bri[i].exit.push_back(d);
		}
		cout<<"����������ϣ�\n";
		int val;
		cout<<"����������Ҫ����������(�����ʹ���ĵ�)����Ҫ���������������0:";
		cin>>val;
		bri[i].type=val;
	}
	
}
inline void OutputObject()
{
	for(int i=1;i<=objectCnt;i++)
	{
		if(obj[i].type=="cube")
		{
			cout<<"translate(["<<obj[i].pos.x<<","<<obj[i].pos.y<<","<<obj[i].pos.z<<"]){";
			cout<<"rotate([0,0,"<<obj[i].rotate<<"]){";
			cout<<"cube(["<<obj[i].sz1<<","<<obj[i].sz2<<","<<obj[i].sz3<<"]);};};\n";
		}
		else if(obj[i].type=="sphere")
		{
			cout<<"translate(["<<obj[i].pos.x<<","<<obj[i].pos.y<<","<<obj[i].pos.z<<"]){";
			cout<<"rotate([0,0,"<<obj[i].rotate<<"]){";
			cout<<"sphere("<<obj[i].sz1<<");};};\n";
		}
		else if(obj[i].type=="cylinder")
		{
			cout<<"translate(["<<obj[i].pos.x<<","<<obj[i].pos.y<<","<<obj[i].pos.z<<"]){";
			cout<<"rotate([0,0,"<<obj[i].rotate<<"]){";
			cout<<"cylinder("<<obj[i].sz1<<","<<obj[i].sz2<<","<<obj[i].sz3<<");};};\n";
		}
	}
}
inline void OutputBridge()
{
	for(int i=1;i<=bridgeCnt;i++)
	{
		Bridge b=bri[i];
		if(b.type==1)//ֱ����
		{
			//��ʱ0<1 2<3�Ѿ����к�
			//|1.first 1.second
			//|0.first 0.second
			//O----
			double z=(bri[i].exit[0].first.z+bri[i].exit[1].first.z)/2.0;
			double delta_z=abs((bri[i].exit[0].first.z-bri[i].exit[1].first.z)/2.0);
			int stairsnum=floor(delta_z/20.0);
			if(bri[i].exit[0].first.y==bri[i].exit[0].second.y)
			{
				double width=bri[i].exit[0].second.x-bri[i].exit[0].first.x;
				for(int j=1;j<=stairsnum;j++)
				{
					objectCnt++;
					obj[objectCnt].type="cube";
					obj[objectCnt].pos=(Dot3){bri[i].exit[0].first.x,bri[i].exit[0].first.y+(j-1)*20.0,bri[i].exit[0].first.z-20+(j-1)*20.0};
					obj[objectCnt].sz1=width;
					obj[objectCnt].sz2=20;
					obj[objectCnt].sz3=40;
				}
				for(int j=1;j<=stairsnum;j++)
				{
					objectCnt++;
					obj[objectCnt].type="cube";
					obj[objectCnt].pos=(Dot3){bri[i].exit[1].first.x,bri[i].exit[1].first.y-j*20.0,bri[i].exit[1].first.z-20-j*20.0};
					obj[objectCnt].sz1=width;
					obj[objectCnt].sz2=20;
					obj[objectCnt].sz3=40;
				}
				objectCnt++;
				obj[objectCnt].type="cube";
				obj[objectCnt].pos=(Dot3){bri[i].exit[0].first.x,bri[i].exit[0].first.y+stairsnum*20.0,z-40};
				obj[objectCnt].sz1=width;
				obj[objectCnt].sz2=bri[i].exit[1].first.y-bri[i].exit[0].first.y-2*stairsnum*20;
				obj[objectCnt].sz3=40;
			}
			else
			{
				double width=bri[i].exit[0].second.y-bri[i].exit[0].first.y;
				for(int j=1;j<=stairsnum;j++)
				{
					objectCnt++;
					obj[objectCnt].type="cube";
					obj[objectCnt].pos=(Dot3){bri[i].exit[0].first.x+(j-1)*20.0,bri[i].exit[0].first.y,bri[i].exit[0].first.z-20.0+(j-1)*20.0};
					
					obj[objectCnt].sz1=20;
					obj[objectCnt].sz2=width;
					obj[objectCnt].sz3=40;
				}
				for(int j=1;j<=stairsnum;j++)
				{
					objectCnt++;
					obj[objectCnt].type="cube";
					obj[objectCnt].pos=(Dot3){bri[i].exit[1].first.x-j*20.0,bri[i].exit[1].first.y,bri[i].exit[1].first.z-40.0-j*20.0};
					obj[objectCnt].sz1=20;
					obj[objectCnt].sz2=width;
					obj[objectCnt].sz3=40;
				}
				objectCnt++;
				obj[objectCnt].type="cube";
				obj[objectCnt].pos=(Dot3){bri[i].exit[0].first.x+stairsnum*20.0,bri[i].exit[0].first.y,z-40};
				obj[objectCnt].sz1=bri[i].exit[1].first.x-bri[i].exit[0].first.x-2*stairsnum*20;
				obj[objectCnt].sz2=width;
				obj[objectCnt].sz3=40;
			}
		}
		//|
		//|   1f 1s
		//|0s        2s
		//|0f        2f
		//O-------------  �̶� ͬ�߶�
		if(b.type==2)
		{
			objectCnt++;
			obj[objectCnt].type="cube";
			obj[objectCnt].pos=bri[i].exit[0].first;
			obj[objectCnt].sz1=bri[i].exit[2].first.x-bri[i].exit[0].first.x;
			obj[objectCnt].sz2=bri[i].exit[0].second.y-bri[i].exit[0].first.y;
			obj[objectCnt].sz3=20;
			objectCnt++;
			obj[objectCnt].type="cube";
			obj[objectCnt].pos=(Dot3){bri[i].exit[1].first.x,bri[i].exit[0].first.y,bri[i].exit[0].first.z};
			obj[objectCnt].sz1=bri[i].exit[1].second.x-bri[i].exit[1].first.x;
			obj[objectCnt].sz2=bri[i].exit[1].second.y-bri[i].exit[0].first.y;
			obj[objectCnt].sz3=20;
			objectCnt++;
			obj[objectCnt].type="cylinder";
			obj[objectCnt].pos=(Dot3){(bri[i].exit[1].first.x+bri[i].exit[1].second.x)/2.0,(bri[i].exit[0].first.y+bri[i].exit[0].second.y)/2.0,bri[i].exit[0].first.z};
			obj[objectCnt].sz1=40;
			obj[objectCnt].sz2=sqrt((bri[i].exit[0].second.y-bri[i].exit[0].first.y)*(bri[i].exit[0].second.y-bri[i].exit[0].first.y)+(bri[i].exit[1].second.x-bri[i].exit[1].first.x)*(bri[i].exit[1].second.x-bri[i].exit[1].first.x))/2.0;
			obj[objectCnt].sz3=sqrt((bri[i].exit[0].second.y-bri[i].exit[0].first.y)*(bri[i].exit[0].second.y-bri[i].exit[0].first.y)+(bri[i].exit[1].second.x-bri[i].exit[1].first.x)*(bri[i].exit[1].second.x-bri[i].exit[1].first.x))/2.0;
		}
		if(b.type==3)
		{
			double x1=b.exit[0].first.x;
			double y1=b.exit[0].first.y;
			double x2=b.exit[0].second.x;
			double y2=b.exit[0].second.y;
			double x3=b.exit[1].first.x;
			double y3=b.exit[1].first.y;
			double x4=b.exit[1].second.x;
			double y4=b.exit[1].second.y;
			double zu=b.exit[0].first.z;
			double zd=b.exit[1].first.z;
			double circleX=((y1+y2)/2.0-(y3+y4)/2.0+(x1*x1-x2*x2)/(y1-y2)/2.0-(x3*x3-x4*x4)/(y3-y4)/2.0)/((x1-x2)/(y1-y2)-(x3-x4)/(y3-y4));
			double circleY=(y1+y2)/2.0-(x1-x2)/(y1-y2)*(circleX-(x1+x2)/2.0);
			double circleZ=(zu+zd)/2.0;
			double circleR=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
			double circleH=40;
			
		}
	}
}

signed main()
{
	freopen("bridge2.in","r",stdin);
	Notice();
	Input();
	OutputBridge();
	freopen("bridge.scad","w",stdout);
	OutputObject();
	freopen("CON","w",stdout);
	cout<<"������.\n���bridge.scad�鿴";
	system("bridge.scad");
	return 0;
}
