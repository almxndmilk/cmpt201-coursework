#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *buff = NULL;
  size_t size = 0;

  while (1) {
    printf("Enter programs to run. \n> ");
    fflush(stdout);

    // invalid then break
    if (getline(&buff, &size, stdin) == -1) {
      break;
    }

    // strip
    buff[strcspn(buff, "\n")] = '\0';

    pid_t pid = fork();
    if (pid == 0) {
      execl(buff, buff, NULL);

      printf("Exec failure\n");
      exit(1);

    } else if (pid > 0) {
      waitpid(pid, NULL, 0);
    }
  }

  free(buff);
  return 0;
}
