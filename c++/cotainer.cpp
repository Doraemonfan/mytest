#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <typeinfo>

using namespace std;

int main() {
    vector<int> vi, vi2;
    list<int> li, li2;
    deque<int> di, di2;
    string str, str2;
    set<int> si, si2;
    map<int, int> mi, mi2;

    vi.swap(vi2);
    li.swap(li2);
    di.swap(di2);
    str.swap(str2);
    si.swap(si2);
    mi.swap(mi2);

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

    return 0;
}
