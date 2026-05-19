#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buff = NULL;
  char *saveptr = NULL;
  size_t size = 0;

  printf("Please enter some text: ");
  size_t num_char = getline(&buff, &size, stdin);

  while ((num_char != -1)) {

    char *ret = strtok_r(buff, " ", &saveptr);

    printf("Tokens:\n");
    printf("%s\n", ret);
    while ((ret = strtok_r(NULL, " ", &saveptr))) {
      printf("%s\n", ret);
    }

    printf("Please enter some text: ");
    num_char = getline(&buff, &size, stdin);
  }

  if (num_char < 0) {
    printf("Couldnt read input");
    free(buff);
    return 1;
  }

  free(buff);

  return 0;
}
