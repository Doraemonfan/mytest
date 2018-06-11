#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ofstream fout("some.dat", ios::out | ios::binary);
    int x = 120;
    fout.write( (const char *)(&x), sizeof(int) );
    fout.close();
    ifstream fin("some.dat", ios::in | ios::binary);
    int y;
    fin.read( (char *)(&y), sizeof(int) );
    fin.close();
    cout << y << endl;
    string s;

    return 0;
}
    
