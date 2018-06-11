#include <iostream>
#include <string>
using namespace std;

const char *str1 = "fanwei";

int main() {
    string s1(str1);
    string s2(str1, 4);
    string s3(s1, 3, 3);
    string s4(10, 'n');
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    s3.append(s2);
    cout << s3 << endl;
    s3.assign(s2);
    cout << s3 << endl;
    s3.insert(1, "tttt");
    cout << s3 << endl;
    string s5 = s3.substr();
    cout << s5 << endl;
    cout << s5.find('a') << endl;
    cout << s5.length() << endl;
    cout << s5.size() << endl;
    s5.swap(s1);
    cout << s5 << endl;
    return 0;
}
