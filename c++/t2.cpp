#include <iostream>
#include <iterator>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

template <typename InputIterator, typename OutputIterator,
            typename UnaryFunction>
OutputIterator Transform(InputIterator first, InputIterator last,
            OutputIterator result, UnaryFunction op) {
    for (; first != last; ++first, ++result)
        *result = op(*first);
    return result;
}

int main() {
    const int N = 5;
    vector<int> s(N);
    for (int i = 0; i < N; ++i)
        cin >> s[i];
    Transform(s.begin(), s.end(), 
            ostream_iterator<int>(cout, "\t"), 
            [](int x) { return x*x; });
    cout << endl;
    return 0;
}
