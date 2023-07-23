#include<bits/stdc++.h>
#include<windows.h>
#define int long long
using namespace std;

//模板库：内置了软件基础的，可以自己写 
//亮点：模板库支持拓展，智能推荐多样化的模板
//交互输入（建筑，入口，出口） 
const int N=1e5+5;
struct Dot3
{
	double x,y,z;
};
struct Object
{
	string type;//类型 
	Dot3 pos;//坐标 
	double sz1,sz2,sz3;
	//cube:a,b,c
	//sphere:r
	//cylinder:h,r1,r2
	double rotate;
}obj[N];
struct Bridge
{
	int exitCnt;//出入口个数
	vector<pair<Dot3,Dot3> >exit;//出入口信息 
	int type;//桥梁类型 
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
	 cout<<"提示:\n";
	 cout<<"1. 请以厘米为单位输入任何长度值.\n";
	 cout<<"2. cylinder的center默认为true.\n";
	 cout<<"3. 请单个桥的出入口宽度保持一致"; 
	cout<<'\n';
}
inline void Input()
{
	cout<<"请输入建筑中物体个数:";
	cin>>objectCnt;
	for(int i=1;i<=objectCnt;i++)
	{
		cout<<"请输入物体类型:";
		string str;
		cin>>str;
		str=toLow(str);
		obj[i].type=str;
		if(str=="cube")
		{
			cout<<"请输入物体坐标:";
			cin>>obj[i].pos.x>>obj[i].pos.y>>obj[i].pos.z; 
			cout<<"请输入物体形状参数:";
			cin>>obj[i].sz1>>obj[i].sz2>>obj[i].sz3;
			cout<<"请输入物体旋转角度:";
			cin>>obj[i].rotate;
			if(i!=objectCnt)cout<<"输入完毕！请输入下一个物体！\n"; 
		}
		else if(str=="sphere")
		{
			cout<<"请输入物体坐标:";
			cin>>obj[i].pos.x>>obj[i].pos.y>>obj[i].pos.z; 
			cout<<"请输入物体形状参数:";
			cin>>obj[i].sz1;
			cout<<"请输入物体旋转角度:";
			cin>>obj[i].rotate;
			if(i!=objectCnt)cout<<"输入完毕！请输入下一个物体！\n"; 
		}
		else if(str=="cylinder")
		{
			cout<<"请输入物体坐标:";
			cin>>obj[i].pos.x>>obj[i].pos.y>>obj[i].pos.z; 
			cout<<"请输入物体形状参数:";
			cin>>obj[i].sz1>>obj[i].sz2>>obj[i].sz3;
			cout<<"请输入物体旋转角度:";
			cin>>obj[i].rotate;
			if(i!=objectCnt)cout<<"输入完毕！请输入下一个物体！\n"; 
		}
		else
		{
			cout<<"非法类型，请重新输入！\n";
			i--;
		}
	}
	cout<<"物体输入完毕！接下来输入桥梁连接情况！\n";
	cout<<"请输入桥梁总数:";
	cin>>bridgeCnt;
	for(int i=1;i<=bridgeCnt;i++)
	{
		cout<<"请输入桥梁入口数:";
		cin>>bri[i].exitCnt;
		cout<<"接下来"<<bri[i].exitCnt<<"行请每行输入两个三维坐标代表入口坐标\n"; 
		for(int j=0;j<bri[i].exitCnt;j++)
		{
			pair<Dot3,Dot3>d;
			cin>>d.first.x>>d.first.y>>d.first.z;
			cin>>d.second.x>>d.second.y>>d.second.z;
			bri[i].exit.push_back(d);
		}
		cout<<"坐标输入完毕！\n";
		int val;
		cout<<"请输入你想要的桥梁类型(请参照使用文档)，想要随机化生成请输入0:";
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
		if(b.type==1)//直线形
		{
			//此时0<1 2<3已经排列好
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
		//O-------------  固定 同高度
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
	cout<<"输出完毕.\n请打开bridge.scad查看";
	system("bridge.scad");
	return 0;
}
