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
#include<map>/*��������*/
#include<memory>/*����ָ��:shared_ptr<>; unique_ptr<>;---p400*/
#include <unordered_set>
#include <unordered_map>
//���ű���֧��C++11
/*
//cin.getline();
getline(cin, s);
//cin >> s;
reverse(s.begin(), s.end());
string::reverse_iterator it = s.rbegin();
*/
//ͨ�������ò������⿽��
//�������������û�е����κ�ȫ�ֱ���������ֱ�Ӹ��ƣ�(ĳ������spfa�㷨ʱ����ʾ ���Ǹ���ʾ)
/*
���ھ���ʱ��Ҫ��1���ӳ�������Ǿ���ʲô�������ݹ�ģ������1���ڳ����أ�
һ����˵��10^6�����ݹ�ģ�������ȹ���
Ҳ����˵����n=1000ʱ��һ���Ҫ��O��n^2�����㷨��
��n=100ʱ��һ������O��n^3�����㷨��
��n=10^4��10^5ʱ��һ������O��nlog2n�����㷨����n��һ����С�����ݵ�ʱ�򣬿��Կ���n!��2^n��
��10^7~10^9��Ҫ������ĳ����ˣ�����С���Թ���������Ͳ�һ���ܹ��ˣ������������
*/

//tips:: ���ʱ�ÿ��������߼���ĺô����� �Ժ�Ĵ���ʱ���Է��ĵĶ�һ���߼����ڵ����ݽ���˳���ƶ�(�����������ƶ�ʱӦ�ñ�ע)

/*
reserve������Ԥ���ռ䣬��������������Ԫ�ض����ڴ�������֮ǰ���������������ڵ�Ԫ�أ���˵������µ�Ԫ��ʱ����Ҫ��push_back()/insert()������

resize�Ǹı������Ĵ�С�����Ҵ���������ˣ������������֮�󣬾Ϳ������������ڵĶ����ˣ���˵������µ�Ԫ��ʱ����operator[]�������������õ�����������Ԫ�ض���

���ߣ�������������ʽ��������ģ�reserve����֮��һ������������ҪԤ���������Ŀռ䣻
resize����������������������һ�������������µĴ�С���ڶ���������Ҫ���������е���Ԫ�أ�������������ʡ�ԣ���ô�͵���Ԫ�ض����Ĭ�Ϲ��캯��
����
�ڴ󲿷�C++��Ŀ�У�һ�㶼�����ʹ�õ�vector���Ͼ���������õĽṹ�� vectorҲ��stl�������Ч��ʵ��֮һ����g++�������£�����-O3�Ż�ѡ���ʱ��vector���������Ч�ʻ����Ϻ�ԭ��������Ч��һ���ߣ���Ȼǰ����ʹ��ǡ����

����push_back�ǿ��µ�����ɱ�֡�
������1��

vector<int> vec;
for(size_t i = 0; i < 130; i ++)
{
vec.push_back(i);
}
������2��

vector<int> vec(130);
for(size_t i = 0; i < 130; i++)
{
vec[i] = i;
}
�ڡ�����1���У��ճ�ʼ����ʱ��vec��������0������ push_back �������·����ڴ档 ������С�ı仯���£�

0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> 128 -> 256
�������˵��ǣ�ÿ�����·��䣬���� 4 -> 8����������У��ڴ˲������ڴ���Ż���Ӱ�죩��

������һ��8�Ŀռ�
����СΪ4������ڴ渴�Ƶ�8�Ŀռ�
����СΪ4����οռ��ͷŵ�
��������2���У��� vector<int> vec(130); ���г�ʼ��������ֱ�Ӿ;��ڴ�һ���Է���ã���СΪ130����

�����ڹ����У�������ǿ���Ԥ֪vector�Ĵ�СΪ���٣������ڳ�ʼ����ʱ���ֱ��ָ����С�� ��������������Լ�ڴ棬���硾����1���ᵼ��vec��ʵ��������С��256����������2��ʵ��������Сֻ��130��

����reserve����޶ȵļ���push_backʱ���ڴ����·���
�ܶ�����º���֪��׼ȷ������������С�����Կ���ʹ�� vector::reserve ��Ԥ��һ���ϴ�������� ������push_back ��ʱ�������Ƶ�����ڴ����·��䣬ֱ��Ԥ���������Ѿ�ʹ�����ˣ�ֻҪԤ����������С�ʵ�����������ĸ��ʺ�С����

ֵ��һ����ǣ��ڽ����CppJieba�����Ż��У�������ƿ���ĵط����򵥵ļ���һ�� reserve ��䣬���ܲ��Խ���������10%��

���ҽ�����Ҫreserve�Ļ��� ������� vector ��ʼ����ʱ������ž�reserve�����������Եù���һЩ���Ͼ��ڴ�Ԥ��Ҳ���ǳ�ʼ����һ���֡�

list<IndexEdgeNode>::const_iterator//�ó��������������ڽӱ�

dubugʱ�Ľ��޼��releaseʱӦ��ȡ��
�����麯���������� �ڵݹ麯���д��ڴ������ʱ���Կ��ǻ�ʵ���� ���Ǳ��������Ż�...
*/


/*
set�ĸ���Ա�����б�����:

1. begin()--����ָ���һ��Ԫ�صĵ�����

2. clear()--�������Ԫ��

3. count()--����ĳ��ֵԪ�صĸ���

4. empty()--�������Ϊ�գ�����true

5. end()--����ָ�����һ��Ԫ�صĵ�����

6. equal_range()--���ؼ����������ֵ��ȵ������޵�����������

7. erase()--ɾ�������е�Ԫ��

8. find()--����һ��ָ�򱻲��ҵ�Ԫ�صĵ�����

9. get_allocator()--���ؼ��ϵķ�����

10. insert()--�ڼ����в���Ԫ��

11. lower_bound()--����ָ����ڣ�����ڣ�ĳֵ�ĵ�һ��Ԫ�صĵ�����

12. key_comp()--����һ������Ԫ�ؼ�ֵ�Ƚϵĺ���

13. max_size()--���ؼ��������ɵ�Ԫ�ص������ֵ

14. rbegin()--����ָ�򼯺������һ��Ԫ�صķ��������

15. rend()--����ָ�򼯺��е�һ��Ԫ�صķ��������

16. size()--������Ԫ�ص���Ŀ

17. swap()--�����������ϱ���

18. upper_bound()--���ش���ĳ��ֵԪ�صĵ�����

19. value_comp()--����һ�����ڱȽ�Ԫ�ؼ��ֵ�ĺ���
*/

//��������תΪ�ַ���: https://blog.csdn.net/chavo0/article/details/51038397

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
	/*��ȡһ����������ָ���һ������ID == B->ID��Ԫ��
	[B](const pB &a){
	return a->ID == B->ID;
	}*/
	/*find_if (beg , end, pred);����ʹ��pred ���ط���ֵ��Ԫ�ء�*/
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
	/*hash<key type�����͵Ķ���������ÿ��Ԫ�صĹ�ϣֵ--p396*/
	return hash<string>() (sd.isbn());
	/*hash:����ļ�׼����壬������������������Ԫ�ص�λ��*/
	/*��ϣ����hash function���������͵�ֵӳ�䵽����(size_t)ֵ�ĺ�����
	��ȵ�ֵ����ӳ�䵽��ͬ������;
	����ȵ�ֵӦ������ӳ�䵽��ͬ������*/
}
/*ʹ��һ����׼��hash ���Ͷ��������㹤SBN ��Ա�Ĺ�ϣֵ����ha sh
���ͽ�����string ����֮�ϡ�
eqOp ����ͨ���Ƚ�ISBN�����Ƚ�����Sales Data ��*/
int eqOp(const Sales_data &lhs, const Sales_data &rhs){
	return lhs.isbn() == rhs.isbn();
}
class Sales__data {
public:
	// �������Ƴ�Ա��ʹ��default
	Sales__data() = default;
	Sales__data(const Sales__data&) = default;
	Sales__data& operator= (const Sales__data&);
	~Sales__data() = default;
};
Sales__data& Sales__data::operator=(const Sales__data&) = default;
class HasPtr{
	friend void swap(HasPtr &, HasPtr&);
public:
	// ���캯�������µ�string ���µļ�����������������Ϊl
	HasPtr(const std::string &s = std::string()) :/*ð�ź�������ǳ�ʼ����Ա�б�*/
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	// �������캯�����������������ݳ�Ա��������������
	HasPtr(const HasPtr &p) :
		ps(p.ps), i(p.i), use(p.use) {
		++*use;
	}
	HasPtr& operator= (const HasPtr&rhs){
		++*rhs.use;
		this->~HasPtr();
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;//ָ��ͬһ���ڴ�
		return *this;
	}
	~HasPtr(){
		if (--*use == 0){//�ݼ����ü���
			delete ps;
			delete use;
		}
	}
private:
	std::string *ps;
	int i;
	std::size_t *use; // ������¼�ж��ٸ������� p s �ĳ�Ա
};
inline/*���ڷ�������Դ���࣬���� swap ������һ�ֺ���Ҫ���Ż��ֶΡ�*/
void swap(HasPtr &lhs, HasPtr&rhs){
	//using std::swap;//ÿ��swap ����Ӧ�ö���δ���޶���
	/*std::swapһ�ο��������θ�ֵ(���ʹ��std::swap(lhs, rhs) ������һ��string�ڴ�,��ʵ���ǲ���Ҫ��,ֻ��Ҫ����ָ�뼴��)*/
	/*swap �ĺ�����Ը��������ÿ�����ݳ�Ա����[��Ӧ��]swap(��������ʹ��std::swap����)*/
	swap(lhs.ps, rhs.ps);//����ָ��
	swap(lhs.i, rhs.i);
}
/*�ϸ���ҵ�ͼģ��:��ȫ��� �ϸ�����(����ʱ�������ֵ)*/
template <typename Key, typename Value>
class StrictMap{
/*˽���鷽��:��������(override)*/
	/*����ȡ*/
	virtual Key getKey(){
		return NULL;
	}
	/*ֵ��ȡ*/
	virtual Value getValue(){
		return NULL;
	}
	/*Խ��ֵ����*/
	virtual Value OverValue(){
		return Value();/*����NULL��һ������?*/
	}
protected:
	map<Key, Value> strictMap;
	/*�ϸ��������*/
	void loadData(){
		strictMap.insert(map<Key, Value>::value_type(getKey(), getValue()));
	}
	/*�ϸ����Key ��û���ҵ� ����Խ��ֵ(reflection:��ӳ)*/
	Value reflection(Key const key){
		static Value overValue = OverValue();/*����Խ��ֵ*/
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
/*�ж���ͼ:�ز���*/
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
	virtual void f1(){//�麯��
		cout << "A is called" << endl;
	}
	virtual void f2() = 0{//���麯��
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
	A<int>* pp = new B<int>;pp->f1();//���B is called,�麯���ɹ�
	ActionMap a;
	a.run();
	auto p = make_shared<int>(42);
	auto q(p);/*��������ṩ��һ�����Ű�Χ�ĳ�ʼ�������Ϳ���ʹ��auto*/
	int obj = 0;
	auto pl = new auto(obj); // p ָ��һ����obj ������ͬ�Ķ���--->�ö�����obj ���г�ʼ��
	//auto p2 = new auto{a, b, c); // ����������ֻ���������ʼ����
	auto r = make_shared<int>(42);
	r = q;
	node B(100);
	cout << sizeof(vector<byte>);
	for (int i = 0; i < 10; i++){
		B.B.push_back(new node(i));
	}
	warn(&B);
	/*Ϊunordered rnultiset ������һ�����ͱ���*/
	using SD_multiset = unordered_multiset <Sales_data,
		decltype(hasher)*, decltype(eqOp)* >;/*���ͻ�ȡ��Decltype����ʾ�ػ��һ��������������Ϣ��*/
	/*������ͱ��С����ϣ����ָ���������ж������ָ��*/
	SD_multiset bookstore(42, hasher, eqOp);
	// ʹ��Foo Hash ���ɹ�ϣֵ�� Foo �����У�������� unordered_set<Foo, decltype(FooHash)*> fooSet(10, FooHash);
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
	//using����ֻ��ָ��һ�����֣����ܴ��βα�
	using Base::menfcn;
	int menfcn(int R, int C) {
		cout << "Derived function with int" << endl;
		return R;
	}
};

//����
int mainForDerived() {
	Base b;
	Derived d;
	b.menfcn();
	d.menfcn();
	d.menfcn(3);
	d.menfcn(3, 6);
	//���ȥ��Derived���е�using����������ִ���error C2660: 'Derived::menfcn' : function does not take 0 arguments
	std::cin.ignore(std::cin.gcount() + 1);//��ջ�����
	std::cin.get();//��ͣ����ִ��
	return 0;
}



/*����ѭ��һ������һ��ѭ�����������������*/
int mainForStdSearch(){
	freopen("input", "r", stdin);
	int n, m;
	while (~scanf("%d%d", &n, &m)){
		using T = int;
		vector<T> total;
		srand(0);
		for (int i = 0; i < 10000000; ++i){
			total.push_back(i + rand());
			deque<int>;//˫�˶���
			queue<int>;//����
			priority_queue<int>;//���ȶ���
			//˫�˶�
			//˫�����ȶ���
			//���ҳɹ��������ص�һ�������λ�á���ⷵ��ֵ�Ƿ����end������O(N)
			find(total.begin(), total.end(), 1);
			//��������������󷵻������ж������Ŀ��
			count(total.begin(), total.end(), 1);
			//�ж��Ƿ����ĳ������O(logN)
			binary_search(total.begin(), total.end(), 1);
			//������������ǣ���һ�����������������ǣ������������
			//����һ��ָ�����ֵ�ĵ�һ������������ҵ��Ļ������ߵ����Բ������ֵ��λ�ã����û�ҵ�����
			//���lower_bound����ʾ���Ķ����ǲ�������Ҫ��ֵ
			//����:����>=����ĵ�һ��λ��  Ŀ�������ڼ�ΪĿ������λ��,��������Ϊ��һ��λ��(������).
			lower_bound(total.begin(), total.end(), 1);
			//����:����>����ĵ�һ��λ��   �����Ƿ���ڶ�Ϊ��һ��λ��.
			upper_bound(total.begin(), total.end(), 1);
			//����������ǣ���ô���Ķ��� 
			equal_range(total.begin(), total.end(), 1);//�ȵ���x�ķ�Χ
			//��׼������������vector��string��deque��list��
			//����������������set��multiset��map��multimap��ʱ�㶼���Լ򵥵���ͬ���ĳ�Ա���������档
			//set�������ظ���ֵ����map�������ظ��ļ� ���set��find��count�ȼ� ��һ����Խ����������ԵĻ�ʹ��find��
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
		puts("��������ض�̬�޷�ʵ��");
		return false;
	}
	virtual bool op(A1Class const &rhs) override{
		puts("b op�������̬: �����麯������Ҳ�޷�ʵ�� �����Ѿ��涨�� ���ǿ���������a�Ļ���������ʵ�ֱ䶯");
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
//����ָ�����
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

//16�ֽ�
struct Node1{
	double d1;

	char c1;
	char c2;
	int i1;
};

//16�ֽ�
struct Node2{
	double d1;

	char c1;
	char c2;
	char c3;
	int i1;
};

//16�ֽ�
struct Node2_1{
	double d1;

	char c1;
	int i1;
};

//24�ֽ�
struct Node3{
	char c1;

	double d1;

	char c2;
	char c3;
	int i1;
};

//2018-7-8 ��ѧ��
void mainForMemoryTest(){
	printf("%d\n", sizeof(Node1));
	printf("%d\n", sizeof(Node2));
	printf("%d\n", sizeof(Node2_1));
	printf("%d\n", sizeof(Node3));
	printf("\n");
}

//����ָ�� <==> pam[][25]
void funcPtrPam(int(*pam)[25]) {

}



void FreeAndDeleteDemo() {
	int *temptr = nullptr;
	//�������������ߵȼ�
	temptr = NULL;
	// ������null ���ظ��ͷ� ���� delete free���ö�û����(����Ҫ����)
	delete temptr;
	delete temptr;
	//delete nullptr; // ����
	free(temptr);
	free(NULL);
	free(nullptr);
}



void mainForStreamDemo() {
	// ��б��(Ʋ�� forward slash'/') ��������, �������, unixϵͳ�б�ʾĿ¼, ��ַ(URL)Ŀ¼(web��ѭunix����)
	// ��б��(��� back slash'\') windowsϵͳ�б�ʾĿ¼
	ifstream input("res/input");
	ofstream output("res/output");
	//ifstream input("input");		  // ������Ŀ��Ŀ¼�µ��ļ�
	//ofstream output("output");
	//ofstream output("res/output");  // 0.��srcĿ¼�µ�output�ļ�
	//ofstream output("res//output"); // 1.�ȼ���0
	//ofstream output("res\output");  // 2.ת��o ��Ч ����Ŀ��Ŀ¼���½� srcoutput �ļ�
	//ofstream output("res\\output"); // 3.�ȼ���0

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
	//�������صĺ������á��¼�����Ϣ�Ĵ��룬����Ϊ���ӣ�hook����
	//C++ʹ���麯������˿�������ʱֱ���޸��麯������������ҹ���
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
	//�麯������
	_tmain(0, nullptr);
	return 0;
}

void overloadFun(std::shared_ptr<int> const &const par) {

}

void overloadFun(std::shared_ptr<int> &const par) {

}

int mainForDemo(){
	/*
	�ڴ�й©���while(true){x = new X(); delete x;}
	tips:
	1.�����ֶβ���������;
	2.û����Ҫ�ֶ�delete��ָ���ֶξ�û��Ҫд��������
	3.����ϵͳ���ڴ���ջ���: ����ϵͳ���ͷ�ָ��xָ��� �������� + ��ʶ��
	4.free(x) = ���߲���ϵͳ����x�ڴ�
	5.delete x <=(x��ȫ��ָ���ֶ�ʱ)=>free(x)
	delete x = x->~destruct(����еĻ�) + ���߲���ϵͳ����x���ڴ�
	delete x <==> x->~destruct() + free(x) (delete�����ú�����滻 ��˳���ܱ�)
	6.�������� x->~destruct() = �����ֶ�.~destruct + �Լ�дdeleteָ���ֶ�(���ն������ȫ�ǻ����������)
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
	/****��̬չʾ
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

void(*customVisit)(int r, int c) = [](int r, int c){};//nullptr�Զ������
/*void setCustomVisitFun(void(*customVisitFun)(int r, int c)){
customVisit = customVisitFun;
}*/
template<class Fun>
void setCustomVisitFun(Fun &customVisitFun){
	customVisit = customVisitFun;
}
