#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <list>
using namespace std;

class NumList {
public:
    void newId(int id) 
    {
        mls.insert({id,list<int>()});
    }
    void add(int id, int num) 
    {
        mls[id].push_back(num);
    }
    void merge(int id1, int id2) 
    {    
       // mls[id1].splice(mls[id1].begin(), mls[id2]);
        mls[id1].merge(mls[id2]);
    }
    void unique(int id) 
    {
        mls[id].unique();
    }
    void out(int id) 
    {
        mls[id].sort();
        list<int> &lst = mls[id];
        copy(lst.begin(), lst.end(), 
                ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    int size(int id)
    {
        if (mls.count(id)) return mls[id].size();
        else return -1;
    }
private:
    unordered_map<int, list<int> > mls;
};

int main() {
    freopen("in.txt", "r", stdin);
//    freopen("out2.txt", "w", stdout);
    NumList nl;
    long n;
    string line, echo;
    int n1, n2;
    cin >> n;
    getline(cin, line);
    int ct = 0;
//    cout << n << endl;
    while (n--) {
        getline(cin, line);
        istringstream sout(line);
        sout >> echo >> n1;
        if (sout) sout >> n2;
//        cout << ++ct << " : " << n << " " << n1 << " "
 //           << nl.size(n1) << endl;
        switch(echo[0]) {
            case 'n': nl.newId(n1); break;
            case 'a': nl.add(n1, n2); break;
            case 'm': nl.merge(n1, n2); break;
            case 'u': nl.unique(n1); break;
            case 'o': nl.out(n1); break;
        }
    }
    return 0;
}
