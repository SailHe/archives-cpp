#ifndef __Work_H
#define __Work_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <time.h>

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

extern FILE *fp;
int Random(int L);
double RandomD(int L);
void PDouble();
char RandomChar(char s, char e);
void IO();
void RandomMatrix(int r, int c, int MaxNum/*元素最大值*/);
/* 从程序的运行结果"test.out"处读取答案与标准(sample.out)进行对比 对比结果输出到Judge.out*/
void Judge(int Line);

#endif