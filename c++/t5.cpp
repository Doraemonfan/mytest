#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    istream_iterator<int> inIt(cin), inEnd;
    vector<int> v(inIt, inEnd);
    sort(v.begin(), v.end());
    deque<int> s2;
    for (vector<int>::iterator iter = v.begin();
            iter != v.end(); ++iter)
        if (*iter % 2 == 0)
            s2.push_back(*iter);
        else 
            s2.push_front(*iter);
    copy(s2.begin(), s2.end(), 
            ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}
