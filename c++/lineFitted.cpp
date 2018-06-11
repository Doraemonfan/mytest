#include <iostream>
#include <algorithm>
using namespace std;

class Point {
public:
    Point(int x = 0, int y = 0): _x(x), _y(y) { } 
    double getX() const { return _x; }
    double getY() const { return _y; }
    
private:
    int _x, _y;
};

void lineFit(const Point points[], int nPoint) 
{
    double avgX = 0, avgY = 0;
    double lxx = 0, lyy = 0, lxy = 0;
    double sumX = 0, sumY = 0;
    for (int i = 0; i < nPoint; ++i) {
        sumX += points[i].getX();
        sumY += points[i].getY();
    }
    avgX = sumX / nPoint;
    avgY = sumY / nPoint;
    for (int i = 0; i < nPoint; ++i) {
        lxx += (points[i].getX()-avgX) * (points[i].getX()-avgX);
        lyy += (points[i].getY()-avgX) * (points[i].getY()-avgY);
        lxy += (points[i].getX()-avgX) * (points[i].getY()-avgY);
    }
    double a = lxy / lxx;
    double b = avgY - a * avgX;
    double r = lxy / sqrt(lxx * lyy);
    cout << "This line can be fitted by y = ax + b." << endl;
    cout << "a = " << a << "  ";
    cout << "b = " << b << "  ";
    cout << "r = " << r << endl;
}
        
constexpr int N = 200;

int main() {
    srand(clock());
    Point p[N];
    for (int i = 0; i < N; ++i) {
        int x = rand() % N, y = rand() % N;
     //   int x = i, y = x * 4 + 5;
        p[i] = Point(x, y);
        cout << "p[" << i << "] = " 
            << "(" << x << "," << y << ")" << endl;;
    }
    lineFit(p, N);

    return 0;
}
    
