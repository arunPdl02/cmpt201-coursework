#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int count = 0;

void *increase_count(void *no_arg) {
  for (int i = 0; i < 10000000; i++) {
    count++;
  }
  return NULL;
}

int main() {
  pthread_t thread1;
  pthread_t thread2;
  if (pthread_create(&thread1, NULL, increase_count, NULL) != 0) {
    printf("Unable to create thread.");
    return 0;
  }

  if (pthread_create(&thread2, NULL, increase_count, NULL) != 0) {
    printf("Unable to create thread.");
    return 0;
  }

  void *retval = 0;
  pthread_join(thread1, &retval);
  pthread_join(thread2, &retval);

  printf("The value of coutn is %d\n", count);
}
