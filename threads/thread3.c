#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int green = 0;
int blue = 1;

pthread_mutex_t mutexgreen = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexblue = PTHREAD_MUTEX_INITIALIZER;

static void *func1(void *arg) {
  printf("thread1 mutex green\n");
  pthread_mutex_lock(&mutexgreen);
  printf("thread1 mutex green acquired\n");

  /*sleep(2);*/

  printf("thread1 blue mutex\n");
  pthread_mutex_lock(&mutexblue);
  printf("thread1 blue mutex acquired\n");
  return NULL;
}

static void *func2(void *arg) {
  printf("thread2 blue mutex\n");
  pthread_mutex_lock(&mutexblue);
  printf("thread2 blue mutex acquired\n");

  /*sleep(2);*/

  printf("thread2 green mutex\n");
  pthread_mutex_lock(&mutexgreen);
  printf("thread2 green lock acquired\n");
  return NULL;
}

int main() {
  pthread_t t1;
  pthread_create(&t1, NULL, func1, NULL);

  sleep(1);
  pthread_t t2;
  pthread_create(&t2, NULL, func2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}
