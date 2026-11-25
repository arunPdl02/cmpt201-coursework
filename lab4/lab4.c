#include <stdio.h>
#include <unistd.h>

#define HEAP_SIZE 256

int main() {
  printf("The current heap allocation is at %p\n", sbrk(0));

  printf("Adding 256 bytes to the heap\n");
  sbrk(256);
  printf("The current heap allocation is at %p\n", sbrk(0));
}
