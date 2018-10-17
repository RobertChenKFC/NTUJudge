#include <stdio.h>
 
int main() {
    int x, a, b, c;
    int y, d, e, f;
    int n;
    scanf("%d%d%d%d", &x, &a, &b, &c);
    scanf("%d%d%d%d", &y, &d, &e, &f);
    scanf("%d", &n);
 
    while (n--) {
        int count = 0;
        while (1) {
            ++count;
            int x1 = x % 3, y1 = y % 3;
            x = (a * x + b) % c;
            y = (d * y + e) % f;
            if ((x1 == 1 && y1 == 0) || (x1 == 2 && y1 == 1) || (x1 == 0 && y1 == 2)) {
                printf("0");
                break;
            } else if ((y1 == 1 && x1 == 0) || (y1 == 2 && x1 == 1) || (y1 == 0 && x1 == 2)) {
                printf("1");
                break;
            }
        }
        printf(" %d\n", count);
    }
}
