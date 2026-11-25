#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void *foo(void *arg) {
  char *my_string = (char *)arg;
  printf("In thread %d: %s\n", gettid(), my_string);
  sleep(1);
  printf("Thread done!\n");
  return (void *)strlen(my_string);
}

int main() {
  printf("thread of the main: %d\n", gettid());
  pthread_t thread;
  if (pthread_create(&thread, NULL, foo, "this is my string") != 0) {
    printf("Unable to create thread.");
    return 0;
  }

  void *retval = 0;
  pthread_join(thread, &retval);
  printf("Thread retured: %lu\n", (unsigned long)(retval));
}
