#include <iostream>

using namespace std;

enum new_enum : unsigned int {
    value1,
    value2,
    value3,
    value4 = 100
};

int main()
{
    cout << new_enum::value4 << endl;

    return 0;
}
