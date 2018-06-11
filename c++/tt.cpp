#include <iostream>
#include <typeinfo>
using namespace std;

int main() 
{
    int *a = new int;
    int *b = new int[10];
    int c[10];
    int (*d)[8][9];
    d = new int[7][8][9];
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    if (typeid(a) == typeid(b)) cout << "a == b" << endl;
    else cout << "a != b" << endl;
    cout << "d size: " << sizeof(d) << endl;
    cout << typeid(d).name() << endl;

    delete a;
    delete[] b;
    delete[] d;
    return 0;
}
