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

// 拷贝赋值 与 拷贝构造器的表面区别(本质上没啥区别)
int runOperatorTest() {

	B b1(1);
	B b2(2);
	// 赋值方法不会对父类进行操作(通常情况下)
	b2 = b1;
	// 构造器有这个条件: 先将rhs向上转型然后拷贝构造, 之后拷贝构造自己 (相等于在子类调用了一个父类的方法)
	B b3(b2);

	return 0;
}
