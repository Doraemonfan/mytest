#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

template <typename T>
void print(T e) 
{
	cout << e << endl;
}

template <typename T, typename... Args> 
void print(T e, Args... args)
{
	cout << e << endl;
	print(args...);
}


int main() {
	print(1, 2.1, "123");
	return 0;
}
