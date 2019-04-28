#include <iostream>
#include <string>
#include <regex>
// @see https://zh.cppreference.com/w/cpp/regex/regex_match
int main()
{
	// 简单正则表达式匹配
	std::string fnames[] = { "foo.txt", "bar.txt", "baz.dat", "zoidberg" };
	std::regex txt_regex("[a-z]+\\.txt");

	for (const auto &fname : fnames) {
		// foo.txt: 1
		// bar.txt: 1
		// baz.dat : 0
		// zoidberg : 0
		std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
	}

	// 提取子匹配
	std::regex base_regex("([a-z]+)\\.txt");
	std::smatch base_match;

	for (const auto &fname : fnames) {
		if (std::regex_match(fname, base_match, base_regex)) {
			// 首个 sub_match 是整个字符串；下个
			// sub_match 是首个有括号表达式。
			if (base_match.size() == 2) {
				std::ssub_match base_sub_match = base_match[1];
				std::string base = base_sub_match.str();
				// foo.txt has a base of foo
				// bar.txt has a base of bar
				std::cout << fname << " has a base of " << base << '\n';
			}
		}
	}

	// 提取几个子匹配
	std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
	std::smatch pieces_match;

	for (const auto &fname : fnames) {
		if (std::regex_match(fname, pieces_match, pieces_regex)) {
			std::cout << fname << '\n';
			for (size_t i = 0; i < pieces_match.size(); ++i) {
				std::ssub_match sub_match = pieces_match[i];
				std::string piece = sub_match.str();
				/*
				foo.txt
				  submatch 0: foo.txt
				  submatch 1: foo
				  submatch 2: txt
				bar.txt
				  submatch 0: bar.txt
				  submatch 1: bar
				  submatch 2: txt
				baz.dat
				  submatch 0: baz.dat
				  submatch 1: baz
				  submatch 2: dat
				*/
				std::cout << "  submatch " << i << ": " << piece << '\n';
			}
		}
	}
}

