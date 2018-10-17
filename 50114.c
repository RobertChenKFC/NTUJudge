#include <stdio.h>
 
inline int abs(int x) {
    return x > 0 ? x : (-x);
}
 
int main() {
    int x[4], y[4];
    for (int i = 0; i < 4; ++i)
        scanf("%d%d", &x[i], &y[i]);
 
    int perim = 0;
    for (int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;
        perim += abs(x[i] - x[j]) + abs(y[i] - y[j]);    
    }
 
    int area =  (x[2] - x[0]) * (y[2] - y[0])
                        - abs(x[2] - x[1]) * abs(y[1] - y[0])
                        - abs(x[3] - x[0]) * abs(y[2] - y[3]);
    printf("%d\n%d\n", perim, area);
}
