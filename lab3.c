#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 5

// Global Variables
char *input_history[MAX_LEN];
int history_count = 0;

// Function Signatures
void add_to_history(char *input);
void remove_oldest_record();
void print_history();
char *get_input();

int main() {
  while (1) {
    char *input = get_input();
    add_to_history(input);
    if (strcmp(input, "print") == 0) {
      print_history();
    }
  }

  while (history_count > 0) {
    remove_oldest_record();
  }

  return 0;
}

char *get_input() {
  char *buff = NULL;
  size_t bufsize = 0;

  printf("Enter input: ");
  ssize_t len = getline(&buff, &bufsize, stdin);

  if (len == -1) {
    printf("Invalid string input. Exiting...\n");
    exit(1);
  }

  // remove newline char at end of input
  if (len > 0 && buff[len - 1] == '\n') {
    buff[len - 1] = '\0';
  }

  return buff;
}

void add_to_history(char *input) {
  if (history_count >= MAX_LEN) {
    remove_oldest_record();
  }
  input_history[history_count] = input;
  history_count++;
}

void remove_oldest_record() {
  if (history_count > 0) {
    // free memory of oldest record
    free(input_history[0]);
    for (int i = 1; i < history_count; i++) {
      input_history[i - 1] = input_history[i];
    }
    history_count--;
  }
}

void print_history() {
  for (int i = 0; i < history_count; i++) {
    printf("%s\n", input_history[i]);
  }
}
