#include <iostream>
#include <functional>
#include <array>

using namespace std;

constexpr int fb(const int n) { return n; }

template <typename T>
bool compare(const T &v1, const T &v2) 
{
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

template <unsigned N, unsigned M>
void fa(const char (&p1)[N], const char (&p2)[M])
{
    cout << "N=" << N << endl;
    cout << "M=" << M << endl;
}

template <typename T>
class A {

    void f1();
};

int main() 
{
    compare(1, 1.3);

    return 0;
}
