#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <iterator>
#include <deque>

using namespace std;

template <typename T, typename InputIterator, 
            typename OutputIterator> 
void mySort(InputIterator first, InputIterator last,
            OutputIterator result)
{
    vector<T> s;
    for (; first != last; ++first, ++result)
        s.push_back(*first);
    sort(s.begin(), s.end());
    copy(s.crbegin(), s.crend(), result);
}

int main() {
    srand(clock());
    double a[5] = { 1.2, 3.4, 0.8, 3.3, 3.2};
    mySort<double>(a, a+5, ostream_iterator<double>(cout, " "));
    cout << endl;
    deque<int> v;
    for (int i = 0; i < 20; ++i)
        v.push_back(rand() % 100);
    mySort<int>(v.begin(), v.end(), 
            ostream_iterator<int>(cout, " "));
    cout << endl;
    auto it = v.begin();
    auto jt = v.begin();
    advance(it, 10);
    cout << "distance: " << distance(v.begin(), v.end()) << endl;
    cout << *it << endl;
    cout << *(jt + 10) << endl;
    mySort<int>(it, v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    mySort<int>(istream_iterator<int>(cin), 
            istream_iterator<int>(), 
            ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}

