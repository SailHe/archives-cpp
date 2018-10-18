#include "DataGenerate.h"
FILE *fp;
/*
文件编程例子
fprintf(fp, "%s\n", s);
fprintf(fp, "%d\n", n);
fgets(ans, 5, fp);
///fprintf(fp, (i == 0 ? "%d %d\n" : "%d %d\n"), le, ri); fprintf(fp, "\n"); ///

srand(time(0));
//随机输入生成
//标程的输入输出
//调用标程的到输出
fp = fopen("sample.in", "w");
freopen("sample.in", "r", stdin);
freopen("sample.out", "w", stdout);
*/
/*
0.StandardPrgram: 得到标程->将其main函数改为solution供数据生成的main调用
1.测试时注释掉带有三个反斜线(///)的语句, 所有输入数据写在input文件内
2.在控制台得出预期结果后打开刚刚注释掉的内容, 当前是从input读入数据结果存入新建的文件夹的0~9.in(out)文件中, 最多支持10组数据
3.另外, 在输出测试数据时, 凡是有输入的地方都需要手动fprintf到fp中, 无法局部的变量使用全局变量*/
#ifndef _PPP_H
#define _PPP_H
//#include"Graph.h"
#include<windows.h>//创建文件夹  

#include<cstring>//memset//
#include<cstdio>//scanf//
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<string>
#include<queue>
#include<list>
#include<map>
#include<functional>
#include<stack>
using namespace std;
#define ALL(object) object.begin(), object.end()
#define FOR(i, bound, limit) for (int i = bound; i < limit; ++i)
FILE *fp = nullptr;///
#endif

int solution(){
	
	return 0;
}

int main(){
	bool flag = CreateDirectory((L"0123"), NULL);//文件夹名
	char nameIn[20] = "0123/0.in";///
	char nameOut[20] = "0123/0.out";///
	/**/
	freopen("input", "r", stdin); //-/
	bool reInput = true;//重复输入
	while (~scanf("%d%d", &n, &c)){

		clock_t Start = clock();///
		freopen(nameOut, "w", stdout);///
		fp = fopen(nameIn, "w");///
		fprintf(fp, "%d %d\n", n, c); ///
		/**/

		solution();

		if (!reInput)
			break;

		++nameIn[5];///
		++nameOut[5];///
		clock_t Stop = clock();
		if ((double)(Stop - Start) > 1000){// (double)(Stop - Start) / CLK_TCK //秒
			puts("超时1000ms");
		}
		/**/
	}
	fclose(fp); ///
	return 0;
}
