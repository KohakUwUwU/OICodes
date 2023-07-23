#pragma once
#include"typeheader.hpp"
#include"xoy.hpp"
const int N=1e5+7;//总元素上限 
const int M=2e5+7;//总桥数上限 
const double EPS=1e-4;
const double PI=3.14159;
const double HOMO=114514;
const Range EmptyRange=(Range){114514,-114514};
Element Data[N];//元素内存池 
int ElementCnt;//元素个数
BridgeInfo bridge[M];//桥梁信息内存池
int BridgeCnt;//桥梁个数 
vector<int>Bri[M];//桥梁联通情况 
bool vis[N];
//表示元素是否为显性元素：
//如果为显性元素，即在输出的时候可以被调用为递归根节点，即该节点为该元素组的代表元素，则设置为true 
//如果为隐性元素，即在输出的时候不可以被直接调用，即该节点不是该元素组的代表元素，则设置为false
//tips:不可以利用vis来部分复制元素组！！！ 
//例：vis[4]={0,1,1,0};
//调用链为1->2->3
//则输出的时候会输出1->2->3 2->3 
//禁止！！ 
