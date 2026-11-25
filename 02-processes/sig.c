#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *message = "CTRL-C pressed\n";
void handle_sigint(int signum) { write(STDOUT_FILENO, message, strlen(message)); }

int main() {
  struct sigaction act = {0};
  act.sa_flags = 0;
  act.sa_handler = handle_sigint;
  sigemptyset(&act.sa_mask);

  if (sigaction(SIGINT, &act, NULL) == -1) {
    perror("Sigaction() failed");
    exit(EXIT_FAILURE);
  }

  pid_t pid = fork();

  if (pid == 0) {
    pid_t parent_pid = getppid();
    while (1) {
      kill(parent_pid, SIGINT);
      sleep(1);
    }
  }
  while (1) {
    sleep(1);
  }
  return 0;
}
