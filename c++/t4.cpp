#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <deque>

using namespace std;

template <typename T>
void output(deque<T> dq) 
{
    copy(dq.begin(), dq.end(), 
            ostream_iterator<T>(cout, " "));
    cout << endl;
}

const int N = 20;

int main() 
{
    srand(clock());
    deque<int> dq1;
    for (int i = 0; i < N; ++i)
        dq1.push_front(rand()%100);
    output<int>(dq1);
    deque<int> dq2(dq1.begin(), dq1.end()-10);
    output<int>(dq2);
    dq2.assign(dq1.begin(),  dq1.end());
    output<int>(dq2);

    cout << "\n# dq3 " << endl;
    deque<int> dq3;
    dq3.resize(20);
    output(dq3);
    cout << dq3.size() << endl;

    deque<int>::iterator it = 
            dq2.insert(dq2.begin(), dq1.rbegin(), dq1.rend());
    output(dq2);
    cout << *it << " " << *(it+1) << endl;
    if (it == dq2.begin()) cout  << "true" << endl;
    cout << "\n# erase" << endl;
    it = dq2.erase(it, dq2.end()-2);
    dq2.push_back(1111);
    output(dq2);
    cout << *it << endl;
    dq2.front() = 23222;
    dq2.back() = 22222;
    dq2.pop_back();
    output(dq2);
    dq2.erase(it);
    cout << "\n# erase2 " << endl;
    output(dq2);
    

    return 0;
}
    
