    #include <iostream>
    #include <cstring>
    using namespace std;

    class Array2 {

	public:
		Array2(int m = 0, int n = 0) {
			struct_arr(m, n);
		}
		~Array2() {
			clear();
		}
		int*& operator[](int r) {
			return _elem[r];
		}
		int operator()(int i, int j) {
			return _elem[i][j];
		}  
		Array2& operator=(const Array2 &a) {
			if (this == &a) return *this;
			clear();
			struct_arr(a._m, a._n);
			memcpy(_elem, a._elem, sizeof(int)*_m*_n);
			return *this;
		}							
	private:
		int _m;
		int _n;
		int **_elem;
		
		void clear() {
			for (int i = 0; i < _m; ++i)
				delete[] _elem[i];
			delete[] _elem;
		}
		void struct_arr(int m, int n) {
			_m = m;
			_n = n;
			_elem = new int*[m];
			for (int i = 0; i < m; ++i)
				_elem[i] = new int[n];
		}
    };

    int main() {
        Array2 a(3,4);
        int i,j;
        for(  i = 0;i < 3; ++i )
            for(  j = 0; j < 4; j ++ )
                a[i][j] = i * 4 + j;
        for(  i = 0;i < 3; ++i ) {
            for(  j = 0; j < 4; j ++ ) {
                cout << a(i,j) << ",";
            }
            cout << endl;
        }
        cout << "next" << endl;
        Array2 b;     b = a;
        for(  i = 0;i < 3; ++i ) {
            for(  j = 0; j < 4; j ++ ) {
                cout << b[i][j] << ",";
            }
            cout << endl;
        }
        return 0;
    }
