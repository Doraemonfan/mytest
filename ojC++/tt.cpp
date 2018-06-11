#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    list<int> a{1, 4, 3, 6, 2, 5};
    list<int> b(a);
    cout << "a : ";
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << "\nb : ";
    for_each(b.begin(), b.end(), [](int n) { cout << n << " "; });
    cout << endl;
   // b.splice(b.begin(), a);
    b.merge(a);
    cout << "a : ";
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << "\nb : ";
    for_each(b.begin(), b.end(), [](int n) { cout << n << " "; });
    cout << endl;

    return 0;
}



    
