#include <ios>
#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    ofstream file("in1.txt", ios_base::trunc | ios_base::binary);
    int nums[] = { 111, 112, 113, 114, 115 };
    double values[] = { 1.23, 34.45, 324.56, 35.59, 58.34 };
    string names[] = { "zoot", "Jimmy", "Al", "Stan", "Moli" };
    file << setiosflags(ios_base::fixed);
    for (int i = 0; i < 5; ++i) {
        file << setiosflags(ios_base::left)
            << setw(10) << nums[i] 
            << setw(6) << names[i]
            << resetiosflags(ios_base::left)
            << setw(10) << setprecision(1) << values[i] << endl;
    }
    file.put('\n');
    file.put('A');
    streampos i = file.tellp();
    cout << "pos: " << i << endl;
    file.seekp(-100);
    file.put('\n');
    file.write(reinterpret_cast<char *>(names), sizeof(names));
    file.close();
    ifstream ifile("in1.txt", ios_base::in | ios_base::binary);
    string str;
    while (getline(ifile, str)) {
        cout << str << endl; 
    }
    cout << endl;
    ifile.close();
    return 0;
}
