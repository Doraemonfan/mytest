#include <iostream>
using namespace std;

class A {
    public:
        A(int a_ = 0): a(a_) { }
        void show() const 
        {
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "c = " << c << endl;
        }
    private:

        const int a;
        static int b;
        static const int c = 3;
};


int A::b = 2;


int main() {
    A t;
    t.show();

    return 0;
}
