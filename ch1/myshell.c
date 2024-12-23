#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define BUFF_SIZE 1024
int main() {
  char buf[BUFF_SIZE];
  pid_t pid;
  int status;
  printf("> ");
  while (fgets(buf, BUFF_SIZE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) - 1] = 0;
    if (strcmp(buf, "exit") == 0 || strcmp(buf, "quit") == 0) {
      printf("Good Bye!");
      return 0;
    }
    if ((pid = fork()) < 0) {
      err_sys("fork error");
    } else if (pid == 0) {
      execlp(buf, buf, NULL);
      err_ret("execute file error %s", buf);
      exit(127);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error");
    }
    printf("> ");
  }
  return 0;
}
