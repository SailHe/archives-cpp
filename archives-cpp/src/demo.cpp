#include <windows.h>
#include <conio.h>//getch//
#include <time.h>
#include<cstring>//memset//
#include<cstdio>//scanf//
#include <fstream>
#include <iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<string>
#include<queue>
#include<list>
#include<functional>
#include<map>/*关联数组*/
#include<memory>/*智能指针:shared_ptr<>; unique_ptr<>;---p400*/
#include <unordered_set>
#include <unordered_map>
//蓝桥杯不支持C++11
/*
//cin.getline();
getline(cin, s);
//cin >> s;
reverse(s.begin(), s.end());
string::reverse_iterator it = s.rbegin();
*/
//通过传引用参数避免拷贝
//福利：这个函数没有调用任何全局变量，可以直接复制！(某度搜索spfa算法时的提示 算是个启示)
/*
而在竞赛时是要求1秒钟出结果，那具体什么样的数据规模可以在1秒内出答案呢？
一般来说，10^6的数据规模都可以稳过。
也就是说，当n=1000时，一般就要用O（n^2）的算法；
当n=100时，一般是用O（n^3）的算法；
当n=10^4或10^5时，一般是用O（nlog2n）的算法；当n是一个很小的数据的时候，可以考虑n!或2^n；
而10^7~10^9就要看程序的常数了，常数小可以过，常数大就不一定能过了，视情况而定。
*/

//tips:: 编程时用空行区分逻辑块的好处在于 以后改代码时可以放心的对一个逻辑块内的内容进行顺序移动(若不能随意移动时应该标注)

/*
reserve是容器预留空间，但并不真正创建元素对象，在创建对象之前，不能引用容器内的元素，因此当加入新的元素时，需要用push_back()/insert()函数。

resize是改变容器的大小，并且创建对象，因此，调用这个函数之后，就可以引用容器内的对象了，因此当加入新的元素时，用operator[]操作符，或者用迭代器来引用元素对象。

再者，两个函数的形式是有区别的，reserve函数之后一个参数，即需要预留的容器的空间；
resize函数可以有两个参数，第一个参数是容器新的大小，第二个参数是要加入容器中的新元素，如果这个参数被省略，那么就调用元素对象的默认构造函数
背景
在大部分C++项目中，一般都会大量使用到vector，毕竟数组是最常用的结构。 vector也是stl里面最高效的实现之一，在g++编译器下，开启-O3优化选项的时候，vector的随机访问效率基本上和原生的数组效率一样高，当然前提是使用恰当。

滥用push_back是可怕的性能杀手。
【代码1】

vector<int> vec;
for(size_t i = 0; i < 130; i ++)
{
vec.push_back(i);
}
【代码2】

vector<int> vec(130);
for(size_t i = 0; i < 130; i++)
{
vec[i] = i;
}
在【代码1】中，刚初始化的时候vec的容量是0，随着 push_back 依次重新分配内存。 容量大小的变化如下：

0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> 128 -> 256
而且忧伤的是，每次重新分配，比如 4 -> 8的这个过程中（在此不考虑内存池优化的影响）：

先申请一个8的空间
将大小为4的这段内存复制到8的空间
将大小为4的这段空间释放掉
而【代码2】中，在 vector<int> vec(130); 这行初始化代码中直接就就内存一次性分配好（大小为130）。

所以在工程中，如果我们可以预知vector的大小为多少，尽量在初始化的时候就直接指定大小。 这样既能做到节约内存，比如【代码1】会导致vec的实际容量大小是256，而【代码2】实际容量大小只有130。

善用reserve最大限度的减少push_back时的内存重新分配
很多情况下很难知道准确的所需容量大小，所以可以使用 vector::reserve 先预留一个较大的容量。 这样在push_back 的时候就无需频繁的内存重新分配，直到预留的容量已经使用完了（只要预留的容量大小适当，遇上用完的概率很小）。

值得一提的是，在今天的CppJieba性能优化中，在性能瓶颈的地方，简单的加了一行 reserve 语句，性能测试结果就提高了10%。

而且建议需要reserve的话， 最好是在 vector 初始化的时候紧接着就reserve，这样代码显得规整一些，毕竟内存预留也算是初始化的一部分。

list<IndexEdgeNode>::const_iterator//用常量迭代器遍历邻接表

dubug时的界限检查release时应该取消
调用虚函数开销极大 在递归函数中存在此类调用时可以考虑换实现了 但是编译器有优化...
*/


/*
set的各成员函数列表如下:

1. begin()--返回指向第一个元素的迭代器

2. clear()--清除所有元素

3. count()--返回某个值元素的个数

4. empty()--如果集合为空，返回true

5. end()--返回指向最后一个元素的迭代器

6. equal_range()--返回集合中与给定值相等的上下限的两个迭代器

7. erase()--删除集合中的元素

8. find()--返回一个指向被查找到元素的迭代器

9. get_allocator()--返回集合的分配器

10. insert()--在集合中插入元素

11. lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器

12. key_comp()--返回一个用于元素间值比较的函数

13. max_size()--返回集合能容纳的元素的最大限值

14. rbegin()--返回指向集合中最后一个元素的反向迭代器

15. rend()--返回指向集合中第一个元素的反向迭代器

16. size()--集合中元素的数目

17. swap()--交换两个集合变量

18. upper_bound()--返回大于某个值元素的迭代器

19. value_comp()--返回一个用于比较元素间的值的函数
*/

//各种类型转为字符串: https://blog.csdn.net/chavo0/article/details/51038397

#define infinity 2147483647
#define N 100000+5
using namespace std;
typedef __int64 I64;

using namespace std::placeholders;
typedef struct node* pB;
int k = 0;
struct node{
	vector<pB> B;
	int ID;
	node(int id){
		ID = id;
	}
};
int checkID(pB &a, int id){
	return a->ID == id;
}
void warn(pB B){
	/*获取一个迭代器，指向第一个满足ID == B->ID的元素
	[B](const pB &a){
	return a->ID == B->ID;
	}*/
	/*find_if (beg , end, pred);查找使得pred 返回非零值的元素。*/
	vector<pB>::iterator it = find_if(B->B.begin(), B->B.end(), 
		bind(checkID, _1, 9));
	if (it == B->B.end())
		return;
}
struct Sales_data{
	int isbn_() const{
		return 1;
	}
	string bookNo;
	string isbn() const{
		return bookNo;
	}
};
size_t hasher(const Sales_data &sd){
	/*hash<key type＞类型的对象来生成每个元素的哈希值--p396*/
	return hash<string>() (sd.isbn());
	/*hash:特殊的际准库棋板，无序容器用它来管理元素的位置*/
	/*哈希函数hash function将给定类型的值映射到整形(size_t)值的函数。
	相等的值必须映射到相同的整数;
	不相等的值应尽可能映射到不同整数。*/
}
/*使用一个标准库hash 类型对象来计算工SBN 成员的哈希值，该ha sh
类型建立在string 类型之上。
eqOp 函数通过比较ISBN号来比较两个Sales Data 。*/
int eqOp(const Sales_data &lhs, const Sales_data &rhs){
	return lhs.isbn() == rhs.isbn();
}
class Sales__data {
public:
	// 拷贝控制成员；使用default
	Sales__data() = default;
	Sales__data(const Sales__data&) = default;
	Sales__data& operator= (const Sales__data&);
	~Sales__data() = default;
};
Sales__data& Sales__data::operator=(const Sales__data&) = default;
class HasPtr{
	friend void swap(HasPtr &, HasPtr&);
public:
	// 构造函数分配新的string 和新的计数器，将计数器置为l
	HasPtr(const std::string &s = std::string()) :/*冒号后的内容是初始化成员列表*/
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	// 拷贝构造函数拷贝所有三个数据成员，并递增计数器
	HasPtr(const HasPtr &p) :
		ps(p.ps), i(p.i), use(p.use) {
		++*use;
	}
	HasPtr& operator= (const HasPtr&rhs){
		++*rhs.use;
		this->~HasPtr();
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;//指向同一块内存
		return *this;
	}
	~HasPtr(){
		if (--*use == 0){//递减引用计数
			delete ps;
			delete use;
		}
	}
private:
	std::string *ps;
	int i;
	std::size_t *use; // 用来记录有多少个对象共享＊ p s 的成员
};
inline/*对于分配了资源的类，定义 swap 可能是一种很重要的优化手段。*/
void swap(HasPtr &lhs, HasPtr&rhs){
	//using std::swap;//每个swap 调用应该都是未加限定的
	/*std::swap一次拷贝和两次赋值(如果使用std::swap(lhs, rhs) 会多分配一次string内存,事实上是不必要的,只需要交换指针即可)*/
	/*swap 的函数体对给定对象的每个数据成员调用[对应的]swap(内置类型使用std::swap即可)*/
	swap(lhs.ps, rhs.ps);//交换指针
	swap(lhs.i, rhs.i);
}
/*严格查找地图模板:安全添加 严格索引(查找时不添加新值)*/
template <typename Key, typename Value>
class StrictMap{
/*私有虚方法:必须重载(override)*/
	/*键获取*/
	virtual Key getKey(){
		return NULL;
	}
	/*值获取*/
	virtual Value getValue(){
		return NULL;
	}
	/*越界值定义*/
	virtual Value OverValue(){
		return Value();/*返回NULL是一个概念?*/
	}
protected:
	map<Key, Value> strictMap;
	/*严格加载数据*/
	void loadData(){
		strictMap.insert(map<Key, Value>::value_type(getKey(), getValue()));
	}
	/*严格查找Key 若没有找到 返回越界值(reflection:反映)*/
	Value reflection(Key const key){
		static Value overValue = OverValue();/*索引越界值*/
		//map<Key, Value>::iterator
		auto it = strictMap.find(key);
		if (it != strictMap.end())
			return strictMap[key];
		else
			return overValue;
	}
	StrictMap(){}
	virtual ~StrictMap(){}
};
/*行动地图:重查找*/
struct ActionMap : protected StrictMap<int, int*>{
public:
	void run(){
		for (int i = 0; i < 5; i++){
			loadData();
		}
		printf("%d\R\R", *reflection(20));
		printf("%d\R\R", *OverValue());
	}
private:
	int* OverValue() override{
		return new int(-1);
	}
	int getKey() override{
		return int(rand() % 5);
	}
	int* getValue() override{
		return new int(rand() % 100);
	}
};


template <typename T>
class A{
public:
	virtual void f1(){//虚函数
		cout << "A is called" << endl;
	}
	virtual void f2() = 0{//纯虚函数
		cout << "A=0" << endl;
	}
};

template <typename T>
class B : public A<T>{
public:
	void f1(){
		cout << "B is called" << endl;
	}
	void f2(){
		cout << "B!=0" << endl;
	}
};

struct Dclass{
	int *a;
	Dclass(){
		a = new int();
	}
};

int mainForVirtualFunction(){
	A<int>* pp = new B<int>;pp->f1();//输出B is called,虚函数成功
	ActionMap a;
	a.run();
	auto p = make_shared<int>(42);
	auto q(p);/*如果我们提供了一个括号包围的初始化器，就可以使用auto*/
	int obj = 0;
	auto pl = new auto(obj); // p 指向一个与obj 类型相同的对象--->该对象用obj 进行初始化
	//auto p2 = new auto{a, b, c); // 错误：括号中只能有羊个初始化器
	auto r = make_shared<int>(42);
	r = q;
	node B(100);
	cout << sizeof(vector<byte>);
	for (int i = 0; i < 10; i++){
		B.B.push_back(new node(i));
	}
	warn(&B);
	/*为unordered rnultiset 定义了一个类型别名*/
	using SD_multiset = unordered_multiset <Sales_data,
		decltype(hasher)*, decltype(eqOp)* >;/*类型获取（Decltype）显示地获得一个变量的类型信息。*/
	/*参数是捅大小、哈希函数指针和相等性判断运算符指针*/
	SD_multiset bookstore(42, hasher, eqOp);
	// 使用Foo Hash 生成哈希值； Foo 必须有＝＝运算符 unordered_set<Foo, decltype(FooHash)*> fooSet(10, FooHash);
	void(*signal1(int sig, void(*func)(int)))(int);
	typedef void(*ptr_to_func)(int);
	ptr_to_func signal2(int, ptr_to_func);
	return 0;
}


class Base {
public:
	void menfcn() {
		cout << "Base function" << endl;
	}

	void menfcn(int R) {
		cout << "Base function with int" << endl;
	}

};

class Derived : public Base {
public:
	//using声明只能指定一个名字，不能带形参表
	using Base::menfcn;
	int menfcn(int R, int C) {
		cout << "Derived function with int" << endl;
		return R;
	}
};

//导出
int mainForDerived() {
	Base b;
	Derived d;
	b.menfcn();
	d.menfcn();
	d.menfcn(3);
	d.menfcn(3, 6);
	//如果去掉Derived类中的using声明，会出现错误：error C2660: 'Derived::menfcn' : function does not take 0 arguments
	std::cin.ignore(std::cin.gcount() + 1);//清空缓冲区
	std::cin.get();//暂停程序执行
	return 0;
}



/*两个循环一条语句和一个循环两条语句有区别吗*/
int mainForStdSearch(){
	freopen("input", "r", stdin);
	int n, m;
	while (~scanf("%d%d", &n, &m)){
		using T = int;
		vector<T> total;
		srand(0);
		for (int i = 0; i < 10000000; ++i){
			total.push_back(i + rand());
			deque<int>;//双端队列
			queue<int>;//队列
			priority_queue<int>;//优先队列
			//双端堆
			//双端优先队列
			//查找成功立即返回第一个对象的位置。检测返回值是否等于end迭代器O(N)
			find(total.begin(), total.end(), 1);
			//查找完整个区间后返回区间中对象的数目。
			count(total.begin(), total.end(), 1);
			//判断是否存在某个对象O(logN)
			binary_search(total.begin(), total.end(), 1);
			//“它在吗？如果是，第一个拷贝在哪里？如果不是，它将在哪里？”
			//返回一个指向这个值的第一个拷贝（如果找到的话）或者到可以插入这个值的位置（如果没找到）的
			//检测lower_bound所标示出的对象是不是你需要的值
			//下限:返回>=对象的第一个位置  目标对象存在即为目标对象的位置,不存在则为后一个位置(迭代器).
			lower_bound(total.begin(), total.end(), 1);
			//上限:返回>对象的第一个位置   无论是否存在都为后一个位置.
			upper_bound(total.begin(), total.end(), 1);
			//它在吗，如果是，那么在哪儿？ 
			equal_range(total.begin(), total.end(), 1);//比得上x的范围
			//标准的序列容器（vector、string、deque和list）
			//在搜索关联容器（set、multiset、map和multimap）时你都可以简单的用同名的成员函数来代替。
			//set不允许重复的值，而map不允许重复的键 因此set的find和count等价 但一般而言仅仅检查存在性的话使用find好
		}
		return 0;
	}
}


class virParent{
public:
	virtual void test(virParent &rhs) = 0;
};

class virChild : public virParent{
public:
	static int i;
	virtual void test(virParent &rhs) override{
		if (i-- >= 0){
			rhs.test(*this);
		}
		printf("--");
		return;
	}
};
int virChild::i = 1;

class A1Class{
public:
	int a;
public:
	A1Class(int i){
		a = i;
	}
	int willPolymorphism(A1Class &rhs);
	virtual bool op(A1Class const &rhs){
		puts("a op");
		return a < rhs.a;
	}
	bool operator<(A1Class const &rhs){
		return op(rhs);
	}
};

class A2Class : public A1Class{
public:
	A2Class(int i) : A1Class(i){}
	bool operator<(A2Class const &rhs){
		puts("运算符重载多态无法实现");
		return false;
	}
	virtual bool op(A1Class const &rhs) override{
		puts("b op运算符多态: 基于虚函数重载也无法实现 参数已经规定了 但是可以在类型a的基础上作出实现变动");
		return 10 < 11;
	}
};

int A1Class::willPolymorphism(A1Class &rhs){
	if (typeid(rhs) == typeid(A1Class)){
		return typeid(*this) == typeid(A1Class) ? 1 : -1;
	}
	else if (typeid(rhs) == typeid(A2Class)){
		return typeid(*this) == typeid(A1Class) ? 2 : -2;
	}
	else{
		return 0;
	}
}

void opp(A1Class *a, A1Class *b){
	*a < *b;
}

shared_ptr<A1Class const> p2;
//智能指针测试
shared_ptr<A1Class const> fun(A1Class *p1_, A1Class *p2_){
	shared_ptr<A1Class const> pA1;
	pA1.reset(p2_);
	p2.reset(p2_);
	bool re = pA1 < p2;
	re = pA1 == p2;
	re = pA1 > p2;
	p2.unique();
	p2.reset();
	return pA1;
}

//16字节
struct Node1{
	double d1;

	char c1;
	char c2;
	int i1;
};

//16字节
struct Node2{
	double d1;

	char c1;
	char c2;
	char c3;
	int i1;
};

//16字节
struct Node2_1{
	double d1;

	char c1;
	int i1;
};

//24字节
struct Node3{
	char c1;

	double d1;

	char c2;
	char c3;
	int i1;
};

//2018-7-8 短学期
void mainForMemoryTest(){
	printf("%d\n", sizeof(Node1));
	printf("%d\n", sizeof(Node2));
	printf("%d\n", sizeof(Node2_1));
	printf("%d\n", sizeof(Node3));
	printf("\n");
}

//函数指针 <==> pam[][25]
void funcPtrPam(int(*pam)[25]) {

}



void FreeAndDeleteDemo() {
	int *temptr = nullptr;
	//这种意义下两者等价
	temptr = NULL;
	// 由于是null 被重复释放 甚至 delete free混用都没问题(但不要混用)
	delete temptr;
	delete temptr;
	//delete nullptr; // 报错
	free(temptr);
	free(NULL);
	free(nullptr);
}



void mainForStreamDemo() {
	// 正斜杠(撇杠 forward slash'/') 除法符号, 间隔符号, unix系统中表示目录, 网址(URL)目录(web遵循unix命名)
	// 反斜杠(捺杠 back slash'\') windows系统中表示目录
	ifstream input("res/input");
	ofstream output("res/output");
	//ifstream input("input");		  // 访问项目根目录下的文件
	//ofstream output("output");
	//ofstream output("res/output");  // 0.在src目录下的output文件
	//ofstream output("res//output"); // 1.等价于0
	//ofstream output("res\output");  // 2.转义o 无效 在项目根目录下新建 srcoutput 文件
	//ofstream output("res\\output"); // 3.等价于0

	int n;
	input >> n;
	output << n << endl;

	input.close();
	output.close();
}



using ticket = int;
class VirtualTable {  // example class  
public:
	virtual void VirtualFunction01(ticket);
};

void VirtualTable::VirtualFunction01(ticket) {
	printf("VirtualFunction01 called");
}

typedef void(__thiscall* VirtualFunction01_t)(ticket* thisptr);
VirtualFunction01_t g_org_VirtualFunction01;

//our detour function  
void __fastcall hk_VirtualFunction01(ticket* thisptr, int edx) {
	printf("Custom function called");
	//call the original function  
	g_org_VirtualFunction01(thisptr);
}
int _tmain(int argc, TCHAR* argv[]) {

	DWORD oldProtection;
	//https://zh.wikipedia.org/wiki/%E9%92%A9%E5%AD%90%E7%BC%96%E7%A8%8B
	VirtualTable* myTable = new VirtualTable();
	void** base = *(void***)myTable;
	//处理被拦截的函数调用、事件、消息的代码，被称为钩子（hook）。
	//C++使用虚函数，因此可在运行时直接修改虚函数表的内容来挂钩。
	VirtualProtect(&base[0], 4, PAGE_EXECUTE_READWRITE, &oldProtection);
	//save the original function  
	g_org_VirtualFunction01 = (VirtualFunction01_t)base[0];
	//overwrite  
	base[0] = &hk_VirtualFunction01;
	VirtualProtect(&base[0], 4, oldProtection, 0);

	//call the virtual function (now hooked) from our class instance  
	myTable->VirtualFunction01(10);

	return 0;
}

int mainForVirtualProtect(){
	//虚函数拦截
	_tmain(0, nullptr);
	return 0;
}

void overloadFun(std::shared_ptr<int> const &const par) {

}

void overloadFun(std::shared_ptr<int> &const par) {

}

int mainForDemo(){
	/*
	内存泄漏检测while(true){x = new X(); delete x;}
	tips:
	1.引用字段不归对象管理;
	2.没有需要手动delete的指针字段就没必要写析构方法
	3.操作系统的内存回收机制: 操作系统会释放指针x指向的 基本类型 + 标识符
	4.free(x) = 告诉操作系统回收x内存
	5.delete x <=(x内全是指针字段时)=>free(x)
	delete x = x->~destruct(如果有的话) + 告诉操作系统回收x的内存
	delete x <==> x->~destruct() + free(x) (delete可以用后面的替换 但顺序不能变)
	6.析构方法 x->~destruct() = 复合字段.~destruct + 自己写delete指针字段(最终对象必须全是基本类型组成)
	*/
	bool re = false;
	auto pA = new A1Class(10);
	auto pA2_1 = new A2Class(10);
	auto pA2 = fun(pA, new A1Class(100));
	auto tempA2Class = A2Class(100);
	int type = pA2_1->willPolymorphism(tempA2Class);
	shared_ptr<virParent> v = shared_ptr<virChild>(new virChild());
	auto tempvirChild = virChild();
	v->test(tempvirChild);
	pA2.reset();/**/
	/****多态展示
	A1Class *ab1 = new A2Class(1);
	A1Class *ab2 = new A2Class(1);
	re = *ab1 < *ab2;
	A2Class b = A2Class(10);
	A1Class a = A1Class(20);
	opp(&a, &b);
	opp(&b, &a);
	re = a < b;****/
	//	re = b < a;
	return 0;
}

void(*customVisit)(int r, int c) = [](int r, int c){};//nullptr自定义访问
/*void setCustomVisitFun(void(*customVisitFun)(int r, int c)){
customVisit = customVisitFun;
}*/
template<class Fun>
void setCustomVisitFun(Fun &customVisitFun){
	customVisit = customVisitFun;
}
