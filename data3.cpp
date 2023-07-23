/*import random
import argparse
import decimal
import numpy as np*/
#pragma GCC optimize(3)
#define DEBUG

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>

typedef unsigned long long ull;
typedef std::uniform_int_distribution<int> uniIntDistrib;
typedef std::default_random_engine randEng;
const int MAX = 100005;
const int MAXREQ = 86005;
const ull p = 998244353;

inline ull inv(const ull& n) {
    ull a = 1, b = n % p, c = p - 2;
    while(c){
        if(c & 1) a = a * b % p;
        b = b * b % p;
        c >>= 1;
    }
    return a;
}


inline ull angleAdd(const ull &a, const ull& b) 
    {return ((a + b) % p) * inv(p + 1 - (a * b) % p) % p;}

inline ull angleSub(const ull &a, const ull& b) 
    {return ((p + a - b) % p) * inv(1 + (a * b) % p) % p;}

inline int validRandint(uniIntDistrib& d, randEng& e, const std::set<int>& invalid){
    int ret = d(e);
    while(invalid.count(ret))
        ret = d(e);
    return ret;
}

std::pair<int, int> randPair(uniIntDistrib& d, randEng& e){
    return std::pair<int, int>(d(e), d(e));
}

std::pair<int, int> orderedRandPair(uniIntDistrib& d, randEng& e){
    std::pair<int, int> ret(d(e), d(e));
    if(ret.first > ret.second)
        std::swap(ret.first, ret.second);
    return ret;
}

ull initial[MAX], rotated[MAX];
int size = 100000, requests = 86000;
std::string inputfile = "data3.in", outputfile = "data3.out";
double rotateP = 0.5;
std::fstream fin(inputfile, std::ios::out), fout(outputfile, std::ios::out);
std::set<int> invalidTan, rotateInvalid;
uniIntDistrib tanMod(0, p - 1), randLine(0, size), randItem(1, size);
std::uniform_real_distribution<double> prob(0.0, 1.0);
randEng randengine(13131313);
int prst;
ull tmpst, tmped;
std::pair<int, int> tmppair;
int rotateTan;
bool flag;

#ifdef DEBUG
double progress = 0.001, delta = 0.001;
#endif

int main(int argc, char *argv[]){
    fin << size << " " << requests << std::endl;
    invalidTan = std::set<int>();
    rotateInvalid = std::set<int>();
    for(int i = 0; i < size; i++){
        prst = validRandint(tanMod, randengine, invalidTan);
        initial[i] = prst;
        if(prst)
            invalidTan.insert(inv(p - prst));
        fin << prst << " ";
    } 
    fin << std::endl;
    invalidTan.clear();
#ifdef DEBUG
    std::cerr << "---Data Initialization End---" << std::endl;
#endif
    for(int _i = 0; _i < requests; _i++){
        if(_i == requests - 1 || prob(randengine) > rotateP) {
            tmppair = randPair(randLine, randengine);
            fin << "2 " << tmppair.first << " " << tmppair.second << std::endl;
            tmpst = tmppair.first != 0 ? initial[tmppair.first - 1] : 0;
            tmped = tmppair.second != 0 ? initial[tmppair.second - 1] : 0;
            fout << angleSub(tmped, tmpst) << std::endl;
        } else {
            tmppair = orderedRandPair(randItem, randengine);
            //rotating = initial[t[0] - 1: t[1]]
            for(int i = tmppair.first - 1; i < tmppair.second; i++)
                if(initial[i]) rotateInvalid.insert(inv(initial[i]));
            for(int i = 0; i < tmppair.first - 1; i++)
                if(initial[i]) invalidTan.insert(inv(p - initial[i]));
            for(int i = tmppair.second; i < size; i++)
                if(initial[i]) invalidTan.insert(inv(p - initial[i]));
            flag = true;
            while(flag){
                rotateTan = validRandint(tanMod, randengine, rotateInvalid);
                flag = false;
                for(int i = tmppair.first - 1; i < tmppair.second; i++){
                    rotated[i] = angleAdd(initial[i], rotateTan);
                    if(invalidTan.count(rotated[i])){
                        flag = true;
                        break;
                    }
                }
            }
            for(int i = tmppair.first - 1; i < tmppair.second; i++)
                initial[i] = rotated[i];
            fin << "1 " << tmppair.first << " " << tmppair.second << " " << rotateTan << std::endl;
            rotateInvalid.clear();
            invalidTan.clear();
        }
#ifdef DEBUG
        if(_i >= progress * requests){
            std::cerr << progress * 100 << "%"" completed" << "\r";
            progress += delta;
        }
#endif
    }
    fin.close();
    fout.close();
}
