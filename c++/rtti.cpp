#include <iostream>
#include <typeinfo>
using namespace std;

class B {
public:
    virtual void a() { cout << "Ba" << endl; }
    void b() { cout << "Bb" << endl; }
    virtual ~B() { }
};

class D: public B {
public:
    void a() override { cout << "Da" << endl; }
    void b() { cout << "Db" << endl; }
    ~D() { }
};

int main() {
    B b1;
    D d1;
    B *bp1 = new D(), *bp2 = new B();
    B &br1 = b1, &br2 = d1;
    cout << typeid(bp1).name() << endl;
    cout << typeid(bp2).name() << endl;
    cout << typeid(br1).name() << endl;
    cout << typeid(br2).name() << endl;
   
    auto func = [](B *bp) {
        bp->a();
        bp->b();
        if (D *dp = dynamic_cast<D*>(bp))
            dp->b();
        else
            bp->b();
    };
    auto func2 = [](B &br) {
        try {
            D &dr= dynamic_cast<D&>(br);
            dr.b();
        } catch (bad_cast) {
            br.b();
        }
    };
    cout << "#bp1" << endl;
    func(bp1);
    cout << "#bp2" << endl;
    func(bp2);
    cout << endl;
    cout << "#bp1" << endl;
    func2(br1);
    cout << "#bp2" << endl;
    func2(br2);


    delete bp1;
    delete bp2;
    return 0;
}
