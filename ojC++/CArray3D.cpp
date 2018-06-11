#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;

template <class T>
class CArray3D {
public:
    class CArray2D {
    public:
        CArray2D(int d2, int d3): _d2(d2), _d3(d3)
        { 
            _elem = new T[d2 * d3];
        }
        ~CArray2D() { delete[] _elem; }
        T* operator[](int r) 
        {
            if (r > _d2) return _elem;
            return _elem + _d3 * r;
        }
        operator void*() { return (void*)_elem; }
    private:
        int _d2, _d3;
        T *_elem;
    };

    CArray3D(int d1, int d2, int d3): _d1(d1)
    { 
        _a3d = new CArray2D*[d1];
        for (int i = 0; i < d1; ++i)
            _a3d[i] = new CArray2D(d2, d3);
    }
    ~CArray3D() {
        for (int i = 0; i < _d1; ++i)
            delete _a3d[i];
        delete[] _a3d;
    }
    CArray2D& operator[](int r) const 
    {
        if (r >= _d1) return *_a3d[0];
        return *_a3d[r];
    }
private:
    int _d1;
    CArray2D **_a3d;
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k) 
                cout << a[i][j][k] << "," ;
            cout << endl;
        }
    }
}
void PrintB()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k) 
                cout << b[i][j][k] << "," ;
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for( int i = 0; i < 3; ++ i ) {
        a[i];
        for( int j = 0; j < 4; ++j ) {
            a[j][i];
            for( int k = 0; k < 5; ++k ) {
                a[i][j][k] = No ++;
            }
            a[j][i][i];	
        }
        
    }
    cout << "#1" << endl;
    PrintA();
    memset(a[1],-1 ,20*sizeof(int));	
    memset(a[1],-1 ,20*sizeof(int));
    PrintA(); 
    memset(a[1][1],0 ,5*sizeof(int));	
    PrintA();

    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0/(i+j+k+1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;
        
    return 0;
}
