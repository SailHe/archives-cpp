#include "DataGenerate.h"
FILE *fp;
/*
�ļ��������
fprintf(fp, "%s\n", s);
fprintf(fp, "%d\n", n);
fgets(ans, 5, fp);
///fprintf(fp, (i == 0 ? "%d %d\n" : "%d %d\n"), le, ri); fprintf(fp, "\n"); ///

srand(time(0));
//�����������
//��̵��������
//���ñ�̵ĵ����
fp = fopen("sample.in", "w");
freopen("sample.in", "r", stdin);
freopen("sample.out", "w", stdout);
*/
/*
0.StandardPrgram: �õ����->����main������Ϊsolution���������ɵ�main����
1.����ʱע�͵�����������б��(///)�����, ������������д��input�ļ���
2.�ڿ���̨�ó�Ԥ�ڽ����򿪸ո�ע�͵�������, ��ǰ�Ǵ�input�������ݽ�������½����ļ��е�0~9.in(out)�ļ���, ���֧��10������
3.����, �������������ʱ, ����������ĵط�����Ҫ�ֶ�fprintf��fp��, �޷��ֲ��ı���ʹ��ȫ�ֱ���*/
#ifndef _PPP_H
#define _PPP_H
//#include"Graph.h"
#include<windows.h>//�����ļ���  

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
	bool flag = CreateDirectory((L"0123"), NULL);//�ļ�����
	char nameIn[20] = "0123/0.in";///
	char nameOut[20] = "0123/0.out";///
	/**/
	freopen("input", "r", stdin); //-/
	bool reInput = true;//�ظ�����
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
		if ((double)(Stop - Start) > 1000){// (double)(Stop - Start) / CLK_TCK //��
			puts("��ʱ1000ms");
		}
		/**/
	}
	fclose(fp); ///
	return 0;
}
