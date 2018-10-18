#include "./DataGenerate.h"
//[1,L]的随机整数
int Random(int L)
{
	time_t t;
	time(&t);
	t%=L;
	return ((rand()*t) % L) + 1;
}
/* 返回double型正小数(0, L] */
double RandomD(int L)
{
	return (double)Random(L) / ((double)Random(9) + 1);
}
//随机字符 s是起点字符 e是终点字符
char RandomChar(char s, char e)
{
	return(rand() % (e-s+1) + s);
}
//随机小数
void PDouble()
{
	printf("%d.%d\n", rand(), rand());
}
//x%的概率
bool ISProbability(int x)
{
	return (rand() % (rand() % 100)) == x;
}
//开流函数
void IO()
{
	/**/
	char *InName = "test.in";
	char *OutName = "test.out";
	/**
	char *InName = "sample.in";
	char *OutName = "sample.out";
	/**/
	fp = fopen(InName, "w");//InName.in的写入
	freopen("sample.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	freopen(OutName, "w", stdout);//设置输出流都输出到OutName
}
/*生成最大值为MaxNum的随机矩阵*/
void RandomMatrix(int r, int c, int MaxNum/*元素最大值*/)
{
	//fprintf(fp, "%d \n", r);
	fprintf(fp, "%d\n", c);
	while (r-- > 0)
	{
		for (int i = 0; i < c; i++)
		{
			fprintf(fp, i ? " " : "");
			fprintf(fp, "%d", Random(MaxNum) - 1);
		}
	}
	fprintf(fp, "\n");
}
/* 从程序的运行结果"test.out"处读取答案与标准(sample.out)进行对比 对比结果输出到Judge.out*/
void Judge(int Line)
{
	//rename(); //http://blog.csdn.net/wangshubo1989/article/details/49559195
	freopen("Judge.out", "w", stdout);
	FILE *fp = fopen("sample.out", "r");
	FILE *fpi = fopen("test.out", "r");
	char c1 = 0, c2 = 0;
	for (int i = 1; i <= Line; i++)
	{
		c1 = c2 = 0;
		while (c1 != 10 && c1 == c2){
			c1 = fgetc(fp);
			c2 = fgetc(fpi);
		}
		printf(c1 == c2 ? "" : "Error in %d\n", i);
	}puts("end");
}