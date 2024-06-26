#include <stdio.h>
#include <string.h>

void different_characters(char *str1, char *str2, char *result) {
  if (str1 == NULL || str2 == NULL || result == NULL) {
    return;
  }

  int length1 = strlen(str1);
  int length2 = strlen(str2);

  int seen[256] = {0};

  for (int i = 0; i < length1; ++i) {
    seen[(int)str1[i]] = 1;
  }

  int k = 0;
  for (int i = 0; i < length2; ++i) {
    if (!seen[(int)str2[i]]) {
      result[k++] = str2[i];
      seen[(int)str2[i]] = 1;
    }
  }

  result[k] = '\0';
}

int main(void) {
  char a[] = "aaB8ccr";
  char b[] = "aAm1Cc";
  char result[256] = {0};
  different_characters(a, b, result);
  printf("Unique characters in b not in a: %s\n", result);

  return 0;
}
