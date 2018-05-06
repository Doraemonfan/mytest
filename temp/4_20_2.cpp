#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class NumberParseException { };

bool isNumber(char *s) {
	if (s == nullptr) return false;
	int len = strlen(s);
	if (len == 0) return false;
	for (int i = 0; i < len; ++i) {
		if (i == 0 && 
			( s[0] == '-' || s[0] == '+'))
			continue;
		else if (!isdigit(s[i]))
			return false;
	}
	return true;
}

int parseNumber(char *s) 
	throw(NumberParseException)
{
	if (!isNumber(s)) 
		throw NumberParseException();
	return atoi(s);
}

int main() {

	char *str1 = "1", *str2 = "a";
	try {
		int num1 = parseNumber(str1);
		int num2 = parseNumber(str2);
		printf("sum is %d\n", num1 + num2);

	} catch (std::range_error) {
	       cout << "range error\n";
	} catch (std::bad_alloc) {
 		cout << "new run out of memory\n";
	} catch (...) {
		cout << "...\n" << endl;
	}

	return 0;
}
