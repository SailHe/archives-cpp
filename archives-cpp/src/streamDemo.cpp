#include<string>
#include<iostream>
#include<fstream>
#include <sstream>
#include <strstream>
int mainForOstrstream() {
	std::ostrstream oss;
	oss << "Sample text: " << 42 << std::ends;
	std::printf("%s\n", oss.str());
	oss.freeze(false); // 启用内存解分配

	std::istringstream s("     this is a test");
	std::string line;
	std::getline(s >> std::ws, line);
	std::cout << "ws + getline returns: \"" << line << "\"\n";

	/*
	std::string inputFilePath = "F:/Temper/inputSheet.csv";
	std::ifstream iFile(inputFilePath);
	std::string readStr((std::istreambuf_iterator<char>(iFile)), std::istreambuf_iterator<char>());
	std::cout << readStr << std::endl;
	*/
	return 0;
}

#include <iostream>
#include <sstream>

int mainForRadix() {
	std::cout << "The number 42 in octal:   " << std::oct << 42 << '\n'
		<< "The number 42 in decimal: " << std::dec << 42 << '\n'
		<< "The number 42 in hex:     " << std::hex << 42 << '\n';
	int n;
	std::istringstream("2A") >> std::hex >> n;
	std::cout << std::dec << "Parsing \"2A\" as hex gives " << n << '\n';
	// 输出基底是持久的，直至更改
	std::cout << std::hex << "42 as hex gives " << 42
		<< " and 21 as hex gives " << 21 << '\n';

	// ofstream: 只写模式打开文件, 如果文件不存在, 可以创建文件 
	// ifstream: 只读模式打开文件, 如果文件不存在, 不会创建, 不能创建空文件读
	// 仅写入且截断文件中已有内容(写截断) 若文件不存在, 以只读模式打开可以创建, 以读/写或写模式不能创建空文件 同时具有 ofstream 和 ifstream 两种功能
	// std::fstream output(outputFilePath, std::ios::out | std::ios::trunc);
	return 0;
}

/*
文件编程例子

fp = fopen(fileNameForFp, "w");
fclose(fp);
fp = NULL;

fprintf(fp, "%s\n", s);
fprintf(fp, "%d\n", n);
fgets(ans, 5, fp);
fprintf(fp, (i == 0 ? "%d %d\n" : "%d %d\n"), le, ri); fprintf(fp, "\n");

srand(time(0));
// 随机输入生成
// 标程的输入输出
// 调用标程的到输出
fp = fopen("sample.in", "w");
// 重定向
freopen("sample.in", "r", stdin);
freopen("sample.out", "w", stdout);
*/
#include <iostream>
#include <fstream>
#include <string>
#include <functional>

void demoForStdRedirect() {
	// @see https://codeday.me/bug/20170701/31772.html
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("out.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	std::string word;
	std::cin >> word;           //input from the file in.txt
	std::cout << word << "  ";  //output to the file out.txt

	std::function<void(void)> f = []() {
		std::string line;
		while (std::getline(std::cin, line))  //input from the file in.txt
		{
			std::cout << line << "\n";   //output to the file out.txt
		}
	};
	f(); //call function


	std::cin.rdbuf(cinbuf);   //reset to standard input again
	std::cout.rdbuf(coutbuf); //reset to standard output again
	in.close();
	out.close();

	std::cin >> word;   //input from the standard input
	std::cout << word;  //output to the standard input
}

int mainForStreamDemo() {
	demoForStdRedirect();
	return 0;
}
