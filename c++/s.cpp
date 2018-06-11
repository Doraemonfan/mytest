#include <sstream>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
string toString(const T &v)
{
    ostringstream sout;
    sout << v;
    return sout.str();
}

template <typename T>
T fromString(const string &str)
{
    istringstream sin(str);
    T v;
    sin >> v;
    return v;
}

int main() {
    double d1 = 1223.44534;
    cout << toString(d1) << endl;
    string s = "12.345";
    double d2 = fromString<double>(s);
    cout << d2 << endl;

    return 0;
}
