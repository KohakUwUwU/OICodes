//Written by MRKR-Ame (Huang Ziyang)
/*
达成效果：
用户输入建筑模型信息、建筑/地面出入口信息、需要达到的建筑联通情况，通过分析器处理，结合内置或用户创建的桥梁要素， 
将结合过新的桥梁的模型源代码输出，可以在OpenSCAD中进行渲染 
运行流程：
用户使用库函数编写建筑模型等信息（样例） -> 放入翻译器&处理器进行分析并输出带天桥的建筑模型源码（SCAD） -> 用户将SCAD手动渲染
实现细节：
首先需要包括类型定义头文件，变量头文件，信息输入头文件，模型处理头文件，源码输出头文件 
用户可以自定义各种元素，最终需要放入内存池当中进行储存（以链表形式）
 
样例编写细节：
关于OpenSCAD的功能介绍和代码语法等请参照：
https://zh.wikibooks.org/wiki/OpenSCAD%E7%94%A8%E6%88%B7%E6%89%8B%E5%86%8C
元素储存在内存池当中
元素当中存储元素参数列表，修饰符列表 
内存池当中元素采用链表访问的形式来实现取并、取交、挖取操作
详见类型定义头文件 
*/
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma once
#include<bits/stdc++.h>
#include"typeheader.hpp"
#include"variety.hpp"
#include"input.hpp"
#include"process.hpp"
#include"output.hpp"
#include"xoy.hpp"
#include"Fx3D.hpp"
#define int long long
using namespace std; 
signed main()
{
	Input_Element();
	//在元素内存池当中输入元素信息
	Input_Connectivity();
	//输入建筑/地面出入口以及联通信息 
	if(Process()==0)Output();
	//处理桥梁，输出源码 
	return 0;
}
