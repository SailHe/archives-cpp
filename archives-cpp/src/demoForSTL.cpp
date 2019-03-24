#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

int runStringDemo() {
	std::string s, ss("balabala");
	s = std::string("这里是移动");
	// 这里是复制
	s = ss;
	return 0;
}

int mainForSTL()
{
	std::vector<int> v{ 1,2,3 };
	std::reverse(std::begin(v), std::end(v));
	for (auto e : v) std::cout << e;
	std::cout << '\n';

	int a[] = { 4, 5, 6, 7 };
	std::reverse(std::begin(a), std::end(a));
	for (auto e : a) std::cout << e;
	return 0;
}

