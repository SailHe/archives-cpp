#include <iostream>

#include <thread>

#include <string>
//using namespace std;

std::thread::id main_thread_id = std::this_thread::get_id();

void pause_thread(int n) {
	//����߳�[��ʱ]��������������״̬ ��ʹ�������е�һ��Ҳ�п�������ȫ��������
	std::thread::id id = std::this_thread::get_id();
	std::cout << id << "���߳�����" << n << "��\n";
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout  << std::this_thread::get_id() << "���߳���������\n";
}

void hello(int n, std::string fname){
	std::cout << "Hello Concurrent World\n";
	if (main_thread_id == std::this_thread::get_id())
		std::cout << "���߳�";
	else
		std::cout << "���߳�";
	std::cout << std::this_thread::get_id() << "\n";
	pause_thread(n);
	if (fname != ""){
		FILE *fp = fopen(fname.c_str(), "wb");
		fwrite(&n, sizeof(n), 1, fp);
	}
}

int mainForThread() {
	//��ʼ�����캯��������һ�� std::thread ���󣬸� std::thread ����ɱ� joinable���²������̻߳���� fn �������ú����Ĳ����� args ������
	std::thread t(hello, 5, "");
	unsigned n = t.hardware_concurrency();
	std::cout << "֧�ֵĲ����߳���: " << n << "\n" << std::endl;
	std::cout << "���ؾ��: " << t.native_handle() << std::endl;
	std::thread a(hello, 20, "for detach thread test");
	/*
	http://www.runoob.com/w3cnote/cpp-std-thread.html
	����(���): ��ֹ��ǰ�̣߳�ֱ������ʶ���߳�*this���������ִ�С�
	ͨ����ʶ���̵߳����*this�� ��ͬ������Ӧ�ĳɹ�����join����������
	û��ͬ��ִ��*�Ȿ���ڶ���̵߳�ͬһ��������ͬʱ����join ����std::thread�����˵���δ������Ϊ�����ݾ�����
	�ɱ� joinable �� std::thread �����������������֮ǰ�����߳� join ���߽�������Ϊ detached.
	*/
	t.join();
	/*
	https://blog.csdn.net/xibeichengf/article/details/71173543
	����: ��ִ���߳����̶߳���ֿ����������ִ��(����?)��һ���߳��˳����κη������Դ�������ͷš� �ڵ���detach *֮��������ӵ���κ��̡߳�
	Detach �̡߳� ����ǰ�̶߳����������ִ��ʵ������̶߳�����룬ʹ���̵߳�ִ�п��Ե������С�һ���߳�ִ����ϣ������������Դ���ᱻ�ͷš�
	���� detach ����֮��*this ���ٴ����κε��߳�ִ��ʵ����
	joinable() == false
	get_id() == std::thread::id()
	���⣬���������� joinable() == false������׳� std::system_error��
	*/
	a.detach();

	/*
	Main�������̶߳���������ˣ�����߳�ûִ�����Ǿͱ�ը�ˡ�
	���Ե���join�������ȴ��߳�ִ����ϡ�
	������detach�ŵ���̨�������ŵ���̨���û���������ˡ�

	��ִ�����̵���������ǰ����Ҫôjoin��Ҫôdetachһ���̡߳�
	*/

	/**/
	std::thread threads[5];// Ĭ�Ϲ����߳� ����һ���յ� std::thread ִ�ж���
	std::cout << "Spawning 5 threads...(��ֵ5���߳�)\n";
	for (int i = 0; i < 5; ++i){
		//�������캯��(������)����ζ�� std::thread ���󲻿ɿ������졣
		//Move ���캯�������óɹ�֮����ֵ�������κ� std::thread ִ�ж���
		//move-assign threads
		threads[i] = std::thread(hello, 13 - 2 * i, "");
	}
	std::cout << "Done spawning threads. Now waiting for them to join: ��ֵ������ڵȴ���������\n";
	for (auto &thread : threads){
		thread.join();
	}
	std::cout << "All threads joined! �����̶߳��ѱ����ӳ��򼴽��˳� ���е��̶߳��󽫻ᱻ���� δ��detach�����ټ���ִ��\n";
	/**/
	return 0;
}

void independentThread()
{
	std::cout << "Starting concurrent thread.(���������߳�)\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Exiting concurrent thread.(�����߳̽���)\n";
}

void threadCaller()
{
	std::cout << "Starting thread caller.\n";
	std::thread t(independentThread);
	//t.join();//���Ӻ󽫻���t���������ִ�����߳�
	t.detach();//����ִ��t�����߳�
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Exiting thread caller.\n";
}

int main_1(){
	threadCaller();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}