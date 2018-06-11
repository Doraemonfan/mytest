#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

constexpr int N = 10;


int main() 
{
    srand(clock());
    auto output = [](list<int> &l) {
        copy(l.begin(), l.end(), 
                ostream_iterator<int>(cout, " "));
        cout << endl;
    };
    list<int> l1;
    for (int i = 0; i < N; ++i)
        l1.push_back(i);
    list<int> l2;
    for (int i = 0; i < N; ++i)
        l2.push_back(i * 10);

    auto out = [&]() {
        cout << "l1: "; output(l1);
        cout << "l2: "; output(l2);
    };
    
    out();
    l1.splice(l1.begin(), l2, l2.begin(), l2.end());
    out();

    return 0;
}
    
