#pragma once
#include<vector>
#include<iostream>
#include"TypeDefine.h"
#include"StdConstDefine.h"
using namespace std;
bool runed[N];
vector<int>Item[N];
int ItemCnt;
double Minx, Maxx, Miny, Maxy, Minz, Maxz;
double xlow[N], xhigh[N], ylow[N], yhigh[N], zlow[N], zhigh[N];
int bl, sx, sy, ex, ey;
Element Data[N];//Ԫ���ڴ�� 
int ElementCnt;//Ԫ�ظ���
BridgeInfo bridge[M];//������Ϣ�ڴ��
int BridgeCnt;//�������� 
vector<int>Bri[M];//������ͨ��� 
bool vis[N];
int stblx[N];
int stbly[N];
int edblx[N];
int edbly[N];
vector<int>blit[500][500];