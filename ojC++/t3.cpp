#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ifstream file1("out1.txt", ios_base::in);
    ifstream file2("out2.txt", ios_base::in);

    string s1, s2;
    int no = 0;
    while (file1 && file2) {
        ++no;
        getline(file1, s1);
        getline(file2, s2);
        if (s1 != s2) {
            cout << "error !" << endl;
            cout << no << endl;
            cout << s1 << endl;
            cout << s2 << endl;
            cout << s1.size() << endl;
            cout << s2.size() << endl;
            cout << s1[38] << " #" << s1[39] << "# " 
                <<  int(s1[39]) << endl;
            cout << s2[38] << " #" << s2[39] << "# "
                << int(s2[39]) << " #" << s2[40] << "# " 
                << int(s2[40]) << endl;
            exit(0);
        }
    }
    cout << "maybe success" << endl;

    return 0;
}
