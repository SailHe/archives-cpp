#include<cstring>//memset//

void demoForMemset() {
	// ���ֽڶ��ڴ����г�ʼ��(���ֽ��ַ�������ȫ���Ե�) PS ��ɲ���MAX_INT32
	// 8bit 7FH: 0111-1111B ==> 4��һ����Byte => 2139062143D
	// �������Բ���洢�� �����ʼ��һ��������Сֵ��������Ҫ����λΪ1
	// -2147483647��
	// 1-111-1111 1111-1111 1111-1111 1111-1111ԭ
	// 1-000-0000 0000-0000 0000-0000 0000-0000��
	// 1-000-0000 0000-0000 0000-0000 0000-0001�� <==> û�й���, ���ܰ��ֽڳ�ʼ��
	// ��һ��
	// 1-111-1111 0111-1111 0111-1111 1000-0000ԭ <==> -2139062144
	// 1-000-0000 1000-0000 1000-0000 0111-1111��
	// 1-000-0000 1000-0000 1000-0000 1000-0000�� ->80H
	int arrayS[20];
	memset(arrayS, 0x80, 20 * sizeof(int));
	memset(arrayS, 0x7f, 20 * sizeof(int));
}