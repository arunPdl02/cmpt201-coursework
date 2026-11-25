#include <stdio.h>
#include <unistd.h>

int main() {
  if (fork() == 0) {
    printf("From the child process");
    fflush(stdin);
    execlp("ls", "ls", ".", "-alh", NULL);
  } else {
    printf("From the child process");
    fflush(stdin);
    execlp("ls", "ls", ".", "-a", NULL);
  }
}
