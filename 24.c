#include <stdio.h>
#include <string.h>

int main() {
  int count[256] = {0};
  char s[100];
  scanf("%s", s);
  char diff = 'A' - 'a';
  for (int i = 0, len = strlen(s); i < len; ++i) {
    if (s[i] >= 'a' && s[i] <= 'z')
      s[i] += diff;
    ++count[s[i]];
  }
  
  int digits = 0;
  for (char i = '0'; i <= '9'; ++i)
    digits += count[i];
  int letters = 0;
  for (char i = 'A'; i <= 'Z'; ++i)
    letters += count[i];
  int vowels = count['A'] + count['E']  + count['I'] + count['O'] + count['U'];
  int consonants = letters - vowels;

  printf("%d %d %d %d\n", digits, letters, vowels, consonants);
}
