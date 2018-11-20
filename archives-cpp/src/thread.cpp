#include <iostream>

#include <thread>

#include <string>
//using namespace std;

std::thread::id main_thread_id = std::this_thread::get_id();

void pause_thread(int n) {
	//这个线程[随时]都可能脱离运行状态 即使输出语句中的一行也有可能是完全乱序的输出
	std::thread::id id = std::this_thread::get_id();
	std::cout << id << "号线程阻塞" << n << "秒\n";
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout  << std::this_thread::get_id() << "号线程重新运行\n";
}

void hello(int n, std::string fname){
	std::cout << "Hello Concurrent World\n";
	if (main_thread_id == std::this_thread::get_id())
		std::cout << "主线程";
	else
		std::cout << "从线程";
	std::cout << std::this_thread::get_id() << "\n";
	pause_thread(n);
	if (fname != ""){
		FILE *fp = fopen(fname.c_str(), "wb");
		fwrite(&n, sizeof(n), 1, fp);
	}
}

int mainForThread() {
	//初始化构造函数，创建一个 std::thread 对象，该 std::thread 对象可被 joinable，新产生的线程会调用 fn 函数，该函数的参数由 args 给出。
	std::thread t(hello, 5, "");
	unsigned n = t.hardware_concurrency();
	std::cout << "支持的并发线程数: " << n << "\n" << std::endl;
	std::cout << "本地句柄: " << t.native_handle() << std::endl;
	std::thread a(hello, 20, "for detach thread test");
	/*
	http://www.runoob.com/w3cnote/cpp-std-thread.html
	连接(会合): 阻止当前线程，直到被标识的线程*this此完成它的执行。
	通过标识的线程的完成*this这 与同步从相应的成功返回join（）方法。
	没有同步执行*这本身。在多个线程的同一个对象上同时调用join （）std::thread构成了导致未定义行为的数据竞争。
	可被 joinable 的 std::thread 对象必须在他们销毁之前被主线程 join 或者将其设置为 detached.
	*/
	t.join();
	/*
	https://blog.csdn.net/xibeichengf/article/details/71173543
	分离: 将执行线程与线程对象分开，允许独立执行(并发?)。一旦线程退出，任何分配的资源都将被释放。 在调用detach *之后，它不再拥有任何线程。
	Detach 线程。 将当前线程对象所代表的执行实例与该线程对象分离，使得线程的执行可以单独进行。一旦线程执行完毕，它所分配的资源将会被释放。
	调用 detach 函数之后：*this 不再代表任何的线程执行实例。
	joinable() == false
	get_id() == std::thread::id()
	另外，如果出错或者 joinable() == false，则会抛出 std::system_error。
	*/
	a.detach();

	/*
	Main结束了线程对象就析构了，如果线程没执行完那就爆炸了…
	所以调用join阻塞，等待线程执行完毕。
	或者用detach放到后台，不过放到后台你就没法控制它了。

	在执行流程到析构函数前总是要么join，要么detach一个线程。
	*/

	/**/
	std::thread threads[5];// 默认构造线程 创建一个空的 std::thread 执行对象。
	std::cout << "Spawning 5 threads...(增值5个线程)\n";
	for (int i = 0; i < 5; ++i){
		//拷贝构造函数(被禁用)，意味着 std::thread 对象不可拷贝构造。
		//Move 构造函数，调用成功之后右值不代表任何 std::thread 执行对象。
		//move-assign threads
		threads[i] = std::thread(hello, 13 - 2 * i, "");
	}
	std::cout << "Done spawning threads. Now waiting for them to join: 增值完成现在等待他们连接\n";
	for (auto &thread : threads){
		thread.join();
	}
	std::cout << "All threads joined! 所有线程都已被连接程序即将退出 所有的线程对象将会被析构 未被detach将不再继续执行\n";
	/**/
	return 0;
}

void independentThread()
{
	std::cout << "Starting concurrent thread.(启动并发线程)\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Exiting concurrent thread.(并发线程结束)\n";
}

void threadCaller()
{
	std::cout << "Starting thread caller.\n";
	std::thread t(independentThread);
	//t.join();//连接后将会在t结束后继续执行主线程
	t.detach();//并发执行t和主线程
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Exiting thread caller.\n";
}

int main_1(){
	threadCaller();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}