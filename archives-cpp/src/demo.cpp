#include <windows.h>
#include <graphics.h>
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
		map<Key, Value>::iterator it = strictMap.find(key);
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
struct d{
	int *a;
	d(){
		a = new int();
	}
};
int main_1(){
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
	using Base::menfcn;  //using����ֻ��ָ��һ�����֣����ܴ��βα�
	int menfcn(int R, int C) {
		cout << "Derived function with int" << endl;
		return R;
	}
};

int main_2() {
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

#include"E:\Projects\myLib\TreeObject.h"

/*����ѭ��һ������һ��ѭ�����������������*/
int main_3(){
	freopen("input", "r", stdin);
	int n, m;
	while (~scanf("%d%d", &n, &m)){
		using T = int;
		vector<T> total;
		srand(0);
		for (int i = 0; i < 10000000; ++i){
			Olympic();
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
int main_4(){
	freopen("input", "r", stdin);
	int n;//������ ��
	srand(0);
	while (true){
		//scanf("%d", &n);
		n = rand() % 10000;
		using T = Student;
		PtrArray<AvlTree<T>> data = PtrArray<AvlTree<T>>(n);//n������
		vector<T> total;
		T in;
		for (int t = 0; t < n; ++t){
			int k;
			//scanf("%d", &k);
			k = rand() % 100;
			in.place = t + 1;
			for (int i = 0; i < k; ++i){
				//scanf("%s%d", &in.id, &in.score);
				in.id[0] = char(rand() % 'Z' + 'A');
				in.score = rand() % 100;
				data[t]->insert(in);
			}//O(N*K*logK)
			int pastId = 0;
			int reCnt = 0;//��ǰԪ�����ڵ��ظ�����
			AvlTree<T>::Position pastP = NULL;
			data[t]->traversal(Tree::RE_ORDER, [&](AvlTree<T>::Position bt){
				if (pastP != NULL && pastP->Data.score == bt->Data.score)
					++reCnt;
				else
					reCnt = 0;
				bt->Data.rank = ++pastId - reCnt;//�ȼ� = ��� - �ظ�����
				total.push_back(bt->Data);
				pastP = bt;
				return false;
			});//O(N*K*logK)
		}
		sort(total.begin(), total.end());//O(log(N*K))
		int len = total.size();
		printf("%d\n", len);
		int pastId = 0;
		int reCnt = 0;//��ǰԪ�����ڵ��ظ�����
		for (int i = len - 1; i >= 0; --i){
			if (i != len - 1 && total[i + 1].score == total[i].score)
				++reCnt;
			else
				reCnt = 0;
			total[i].localRank = total[i].rank;//��������
			total[i].rank = ++pastId - reCnt;//������
			total[i].outPut();
		}//O(N*K)
	}
	return 0;
}

int minCmp(int const &min, int const &max){
	return min - max;
}

int maxCmp(int const &min, int const &max){
	return -minCmp(min, max);
}

template<class T>
void shellSort(T a[], int n){
	int si;
	int sedgewick[] = { 929, 505, 109, 41, 19, 5, 1, 0 };
	for (si = 0; sedgewick[si] >= n; ++si);//�ҵ���һ��С������Ԫ�ظ���������

	for (int d = sedgewick[si]; d > 0; d = sedgewick[++si]){
		/*��������*/
		for (int p = d, i; p < n; ++p){
			T tmp = a[p];
			for (i = p; i >= d && a[i - d] > tmp; i -= d){
				a[i] = a[i - d];//i����[d, p], ��ǰ��"����"a[p]��ֵ����
			}
			//a[i - d] <= tmpʱ ��Ϊǰ�涼�Ǿֲ������ [0, i-d]�����ڵ�ֵ <= a[p]һ������, (i, p]�ڵ�ֵ>a[p]һ������
			a[i] = tmp;//����i����a[p]��λ�� ps��������Ҳ�� ֻ�ǻ�����������õĽ���
		}
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

//����ָ�� <==> pam[][25]
void funcPtrPam(int(*pam)[25]) {

}

//2018-7-8 ��ѧ��
void memoryTest(){
	printf("%d\n", sizeof(Node1));
	printf("%d\n", sizeof(Node2));
	printf("%d\n", sizeof(Node2_1));
	printf("%d\n", sizeof(Node3));
	printf("\n");
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

int main(){
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
	int type = pA2_1->willPolymorphism(A2Class(100));
	shared_ptr<virParent> v = shared_ptr<virChild>(new virChild());
	v->test(virChild());
	pA2.reset();/**/
	/****��̬չʾ****/
	A1Class *ab1 = new A2Class(1);
	A1Class *ab2 = new A2Class(1);
	re = *ab1 < *ab2;
	A2Class b = A2Class(10);
	A1Class a = A1Class(20);
	opp(&a, &b);
	opp(&b, &a);
	re = a < b;
	//	re = b < a;
	/***********/

	/*int aa[] = { 44, 12, 59, 36, 62, 43, 94, 7, 35, 52, 85 };
	shellSort<int>(aa, 11);
	char post[10] = "hfbdcea";
	char in[10] = "hbfadec";
	char pre[10] = "";
	BinTree<char> tt;
	tt.orderTranslation(pre, nullptr, in, post, 7);
	vector<int> a = { 6, 15, 3, 9, 7, 4, 12, 10, 15, 14, 5, 13 };
	int b[10] = { 2, 1, 4, 5, 9, 3, 6, 7 };
	AvlTree<int> t = AvlTree<int>();
	for (int i = 0; i < 8; ++i){
	t.insert(b[i]);
	}
	Heap<int> h = Heap<int>(a.size() + 5);
	h.build(-1, maxCmp);
	for (int i = 0; i < a.size(); ++i)
	h.push(a[i]);
	h.pop();
	h.pop();
	h.pop();
	h.push(8);
	h.push(11);
	puts("");
	h.traversal(h.level, [&](BinTree<int>::BT b){
	printf("%d ", b->Data);
	return false;
	});*/
	return 0;
}



/*void setCustomVisitFun(void(*customVisitFun)(int r, int c)){
customVisit = customVisitFun;
}*/
template<class Fun>
void setCustomVisitFun(Fun &customVisitFun){
	customVisit = customVisitFun;
}
void(*customVisit)(int r, int c) = [](int r, int c){};//nullptr�Զ������


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
