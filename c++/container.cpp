#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <typeinfo>

using namespace std;

template <typename T>
void output(const T &v) {
    copy(v.begin(), v.end(),
            ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    vector<int> vi, vi2(10, 1);
    list<int> li, li2(10, 2);
    deque<int> di, di2(10, 3);
    string str, str2(10, 'a');
    set<int> si, si2;
    map<int, int> mi, mi2;

    cout << "# output" << endl;
    output(vi2);
    output(li2);
    output(di2);
    cout << endl;

    vi.swap(vi2);
    li.swap(li2);
    di.swap(di2);
    str.swap(str2);
    si.swap(si2);
    mi.swap(mi2);

    cout << "# output" << endl;
    output(vi2);
    output(li2);
    output(di2);
    cout << endl;

    vector<int>::iterator vi_it = vi.begin();
    list<int>::iterator li_it = li.begin();
    deque<int>::iterator di_it = di.begin();
    string::iterator str_it = str.begin();
    set<int>::iterator si_it = si.begin();
    map<int, int>::iterator mi_it = mi.begin();
    auto li_rit = list<int>::reverse_iterator(li_it);
    auto li_it2 = li_rit.base();
    map<int, int>::const_reverse_iterator mi_crit = mi.crbegin();
    cout << typeid(mi_crit).name() << endl;
    cout << typeid(li_rit).name() << endl;
    cout << typeid(li_it2).name() << endl;
    cout << typeid(vi_it).name() << endl;
    cout << typeid(li_it).name() << endl;
    for (int i = 0; i < 20; ++i) {
        vi.push_back(i);
        li.push_back(i);
        di.push_back(i);
    }
    for (auto i : str) cout << i << " "; cout << endl;
    cout << vi.begin()[10] << endl;
    return 0;
}
