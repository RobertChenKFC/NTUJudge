#include <stdio.h>
 
int abs(int x) {
    return x > 0 ? x : (-x);
}
 
int main() {
    int dig;
    int cnt = 0;
    int zeros = 0;
    int sum = 0;
    while (scanf("%d", &dig) != EOF) {
        ++cnt;
        if (dig == 0) ++zeros;
        if (cnt & 1) sum += dig;
        else sum -= dig;
    }
    printf("%d\n%d\n%d\n%d\n", cnt, !(dig & 1), zeros, !(abs(sum) % 11));
}
