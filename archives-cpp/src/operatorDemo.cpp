#include<string>
#include<iostream>
#include<fstream>
#include <sstream>
#include <strstream>


class A {
	int a;
public:
	A(int nA) : a(nA) {}
	A(A const &rhs) : a(rhs.a) {}
	A & operator=(A const &rhs) {
		a = rhs.a;
		std::cout << "A=" << std::endl;
		return *this;
	}
};
class B : A {
public:
	B(int nB) :A(nB) {}
	B(B const &rhs) :A(rhs) {}
	B & operator=(B const &rhs) {
		std::cout << "B=" << std::endl;
		return *this;
	}
};

// ������ֵ �� �����������ı�������(������ûɶ����)
int runOperatorTest() {

	B b1(1);
	B b2(2);
	// ��ֵ��������Ը�����в���(ͨ�������)
	b2 = b1;
	// ���������������: �Ƚ�rhs����ת��Ȼ�󿽱�����, ֮�󿽱������Լ� (����������������һ������ķ���)
	B b3(b2);

	return 0;
}
