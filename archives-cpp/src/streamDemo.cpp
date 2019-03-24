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

	/*std::string inputFilePath = "F:/Temper/inputSheet.csv";
	std::ifstream iFile(inputFilePath);
	std::string readStr((std::istreambuf_iterator<char>(iFile)), std::istreambuf_iterator<char>());
	std::cout << readStr << std::endl;*/
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
	return 0;
}

/*
文件编程例子
fprintf(fp, "%s\n", s);
fprintf(fp, "%d\n", n);
fgets(ans, 5, fp);
/// fprintf(fp, (i == 0 ? "%d %d\n" : "%d %d\n"), le, ri); fprintf(fp, "\n"); ///

srand(time(0));
// 随机输入生成
// 标程的输入输出
// 调用标程的到输出
fp = fopen("sample.in", "w");
freopen("sample.in", "r", stdin);
freopen("sample.out", "w", stdout);
*/
