// ============================= 继承的访问修饰符: 去除注释查看
/*
class A {
private:
	int i;
protected:
	int i1;
public:
	int i2;
};

class Bpri :private A {
	Bpri() {
		i = 0;
		i1 = 0;
		i2 = 0;
	}
};

class Bpro :private A {
	Bpro() {
		i = 0;
		i1 = 0;
		i2 = 0;
	}
};

class C :public Bpri {
	B() {
		i = 0;
		i1 = 0;
		i2 = 0;
	}
};
*/
