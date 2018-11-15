#include <stdio.h>
#include <string.h>
 
#define IS_VOWEL(X) ((X) == 'a' || (X) == 'e' || (X) == 'i' || (X) == 'o' || (X) == 'u')
 
int main() {
    char string[500000];
    int cnt = 0;
    char prev, cur = '\0';
    while (scanf("%s", string) != EOF) {
        int len = strlen(string);
        for (int i = 0; i < len; ++i) {
            if (IS_VOWEL(string[i])) continue;
            if (cur == '\0') {
                cur = string[i];
            } else {
                prev = cur;
                cur = string[i];
                if (prev < cur) ++cnt;
            }
        }
    }
    printf("%d\n", cnt);
}
