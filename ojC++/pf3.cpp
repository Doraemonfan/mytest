#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) == 1) 
        for (int a = 2; a <= N; ++a) 
            for (int b = 2; b < a; ++b) 
                for (int c = b; c < a; ++c) 
                    for (int d = c; d < a; ++d) 
                        if (a*a*a == b*b*b + c*c*c + d*d*d)
                            printf("(%d, %d, %d, %d)\n", a, b, c, d);
    return 0;
}
