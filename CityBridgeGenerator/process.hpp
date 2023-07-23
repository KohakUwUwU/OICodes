/*
type:
1 cube 立方体 
2 sphere 球体 
3 cylinder 圆柱体 
4 square 方形 
5 circle 圆形 
*/
#pragma once
bool runed[N];
inline int CheckLink()
{
	for(int i=1;i<=ElementCnt;i++)
	{
		if(vis[i])
		{
			if(runed[i])return 1;
			runed[i]=1;
			int j=i;
			while(Data[j].to)
			{
				j=Data[j].to;
				runed[j]=1;
			}
		}
	}
	return 0;
}
vector<int>Item[N];
int ItemCnt;
inline double LowestPoint(int id)
{
	return Data[id].translate[2];
}
inline int CheckOnFloor()
{
	//建筑分组存入vector 
	for(int i=1;i<=ElementCnt;i++)
	{
		if(vis[i])
		{
			++ItemCnt;
			Item[ItemCnt].push_back(i);
			int j=i;
			while(Data[j].to)
			{
				j=Data[j].to;
				Item[ItemCnt].push_back(j);
			}
		}
	}
	for(int i=1;i<=ItemCnt;i++)
	{
		double lowest=HOMO;
		for(int j=0;j<Item[i].size();i++)
		{
			lowest=min(lowest,LowestPoint(Item[i][j]));
		}
		if(abs(lowest)>EPS)return 1;
	}
	return 0;
}
double Minx,Maxx,Miny,Maxy,Minz,Maxz;
double xlow[N],xhigh[N],ylow[N],yhigh[N],zlow[N],zhigh[N];
int bl,sx,sy,ex,ey;
vector<int>blit[N][N];

inline double DtoR(double d)//角度转弧度
{
	return d/180.0*PI;
}
inline double RtoD(double r)//弧度转角度 
{
	return r/PI*180;
}
inline void getXYrange()
{
	Minx=Miny=Minz=HOMO;
	Maxx=Maxy=Maxz=0;
	for(int i=1;i<=ElementCnt;i++)
	{
		xlow[i]=ylow[i]=zlow[i]=HOMO;
		xhigh[i]=yhigh[i]=zhigh[i]=0;
		if(Data[i].type==1)
		{
			double dot1x=Data[i].translate[1];
			double dot1y=Data[i].translate[2];
			double dot2x=Data[i].translate[1]+Data[i].cdd[2]*cos(DtoR(Data[i].rotate[3]+90.0));
			double dot2y=Data[i].translate[2]+Data[i].cdd[2]*sin(DtoR(Data[i].rotate[3]+90.0));
			double dot3x=Data[i].translate[1]+Data[i].cdd[1]*cos(DtoR(Data[i].rotate[3]));
			double dot3y=Data[i].translate[2]+Data[i].cdd[1]*sin(DtoR(Data[i].rotate[3]));
			double dot4x=dot2x+dot3x-dot1x;
			double dot4y=dot2y+dot3y-dot1y;
			xlow[i]=min(xlow[i],dot1x);
			xlow[i]=min(xlow[i],dot2x);
			xlow[i]=min(xlow[i],dot3x);
			xlow[i]=min(xlow[i],dot4x);
			ylow[i]=min(ylow[i],dot1y);
			ylow[i]=min(ylow[i],dot2y);
			ylow[i]=min(ylow[i],dot3y);
			ylow[i]=min(ylow[i],dot4y);
			xhigh[i]=max(xhigh[i],dot1x);
			xhigh[i]=max(xhigh[i],dot2x);
			xhigh[i]=max(xhigh[i],dot3x);
			xhigh[i]=max(xhigh[i],dot4x);
			yhigh[i]=max(yhigh[i],dot1y);
			yhigh[i]=max(yhigh[i],dot2y);
			yhigh[i]=max(yhigh[i],dot3y);
			yhigh[i]=max(yhigh[i],dot4y);
			zlow[i]=Data[i].translate[3];
			zhigh[i]=Data[i].translate[3]+Data[i].cdd[3];
		}
		if(Data[i].type==2)
		{ 
			xlow[i]=Data[i].translate[1]-Data[i].cdd[1];
			xhigh[i]=Data[i].translate[1]+Data[i].cdd[1];
			ylow[i]=Data[i].translate[2]-Data[i].cdd[1];
			yhigh[i]=Data[i].translate[2]+Data[i].cdd[1];
			zlow[i]=Data[i].translate[3]-Data[i].cdd[1];
			zhigh[i]=Data[i].translate[3]+Data[i].cdd[1];
		}
		if(Data[i].type==3)
		{
			int r=max(Data[i].cdd[2],Data[i].cdd[3]);
			xlow[i]=Data[i].translate[1]-r;
			xhigh[i]=Data[i].translate[1]+r;
			ylow[i]=Data[i].translate[2]-r;
			yhigh[i]=Data[i].translate[2]+r;
			zlow[i]=Data[i].translate[3];
			zhigh[i]=Data[i].translate[3]+h;
		}
		Minx=min(Minx,xlow[i]);
		Maxx=max(Maxx,xhigh[i]);
		Miny=min(Miny,ylow[i]);
		Maxy=max(Maxy,yhigh[i]);
		Minz=min(Minz,zlow[i]);
		Maxz=max(Maxz,zhigh[i]);
	}
	bl=ceil(sqrt(min(x,y)));
	sx=floor(Minx);sy=floor(Miny);
	ex=ceil(Maxx);ey=ceil(Maxy);
}
inline void getHousebl()
{
	for(int i=1;i<=ElementCnt;i++)
	{
		int mnx=floor(xlow[i]);stblx[i]=(mnx-sx)/bl+1;
		int mny=floor(ylow[i]);stbly[i]=(mny-sy)/bl+1;
		int mxx=ceil(xhigh[i]);edblx[i]=(mxx-ex)/bl+1;
		int mxy=ceil(yhigh[i]);edbly[i]=(mxy-ey)/bl+1;
		for(int j=stblx[i];j<=edblx[i];j++)
		{
			for(int k=stbly[i];k<=edbly[i];k++)
			{
				blit[j][k].push_back(i);
			}
		}
	}
}
inline void Bridging()
{
	
}
inline int Process()
{
	if(CheckLink())
	{
		cout<<"Link Error!"<<'\n';
		return 1;
	}
	if(CheckOnFloor())
	{
		cout<<"Not On Floor!"<<'\n';
		return 1;
	}
	getXYrange();
	getHousebl();
	
}
