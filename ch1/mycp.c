#include "apue.h"
#include <unistd.h>

#define BUFFSIZE 4096
int main() {
  char buf[BUFFSIZE];
  int n;
  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      err_sys("write error");
    }
  }
  if (n < 0) {
    err_sys("read error");
  }
  return 0;
}
