#include<iostream>
#include<D:\文档\编程\VSproject\CityBridgeGenerator\header\FunctionDefine.h>
#include<D:\文档\编程\VSproject\CityBridgeGenerator\header\InputData.h>
using namespace std;

int main()
{
	Input_Element();
	//在元素内存池当中输入元素信息
	Input_Connectivity();
	//输入建筑/地面出入口以及联通信息 
	if (Process() == 0)Output();
	//处理桥梁，输出源码
	return 0;
}