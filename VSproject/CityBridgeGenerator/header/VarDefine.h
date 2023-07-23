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
Element Data[N];//元素内存池 
int ElementCnt;//元素个数
BridgeInfo bridge[M];//桥梁信息内存池
int BridgeCnt;//桥梁个数 
vector<int>Bri[M];//桥梁联通情况 
bool vis[N];
int stblx[N];
int stbly[N];
int edblx[N];
int edbly[N];
vector<int>blit[500][500];