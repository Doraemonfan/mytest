#include <iostream>
#include <string>
#include <regex>
#include <functional>
#include <thread>
#include <boost/asio.hpp>

using namespace std;

int main() {
	
/*	
	string fnames[] = { "foo.txt", "bar.txt", "test",
		"a0.txt", "AAA.txt" };
	regex txt_regex("[a-z]+\\.txt");
	for (const auto &fname: fnames)
		cout << fname << ": " 
			<< regex_match(fname, txt_regex) << endl;
	regex base_regex("([a-z]+)\\.txt");
	smatch base_match;
	for (const auto &fname: fnames) {
		if (regex_match(fname, base_match, base_regex)) {
			if (base_match.size() == 2) {
				string base = base_match[1].str();
				cout << "sub-match[0]: "
					<< base_match[0].str()
					<< endl;
				cout << fname << " sub-match[1]: "
					<< base << endl;
			}
		}
	}
*/
/*	function<void(int)> func = [](int a) { 
		cout << a * 10 << endl;
	};
	thread t1(func, 10);
	thread t2(func, 20);
	cout << "t1: " << t1.get_id() << endl;
	cout << "t2: " << t2.get_id() << endl;
	t1.join();
	t2.join();
*/	
	return 0;
}
