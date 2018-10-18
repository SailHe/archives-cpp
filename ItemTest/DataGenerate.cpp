#include "./DataGenerate.h"
//[1,L]���������
int Random(int L)
{
	time_t t;
	time(&t);
	t%=L;
	return ((rand()*t) % L) + 1;
}
/* ����double����С��(0, L] */
double RandomD(int L)
{
	return (double)Random(L) / ((double)Random(9) + 1);
}
//����ַ� s������ַ� e���յ��ַ�
char RandomChar(char s, char e)
{
	return(rand() % (e-s+1) + s);
}
//���С��
void PDouble()
{
	printf("%d.%d\n", rand(), rand());
}
//x%�ĸ���
bool ISProbability(int x)
{
	return (rand() % (rand() % 100)) == x;
}
//��������
void IO()
{
	/**/
	char *InName = "test.in";
	char *OutName = "test.out";
	/**
	char *InName = "sample.in";
	char *OutName = "sample.out";
	/**/
	fp = fopen(InName, "w");//InName.in��д��
	freopen("sample.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	freopen(OutName, "w", stdout);//����������������OutName
}
/*�������ֵΪMaxNum���������*/
void RandomMatrix(int r, int c, int MaxNum/*Ԫ�����ֵ*/)
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
/* �ӳ�������н��"test.out"����ȡ�����׼(sample.out)���жԱ� �ԱȽ�������Judge.out*/
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