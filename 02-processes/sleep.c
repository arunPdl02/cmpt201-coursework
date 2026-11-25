#include <stdio.h>
#include <unistd.h>

int main() {
  for (int i = 0; i < 10; i++) {
    printf("Sleeping %d\n", i);
    fflush(stdout);
    sleep(2);
  }
  printf("DONE!");
}
