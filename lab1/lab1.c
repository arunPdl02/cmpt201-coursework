#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize_and_print(char *str);

int main() {
  char *line = NULL;
  size_t len = 0;
  for (;;) {
    printf("Please enter some text: ");
    if (getline(&line, &len, stdin) == -1L) {
      printf("Getline failure.\n");
      break;
    }
    if (strcmp(line, "\n") == 0) {
      break;
    }
    tokenize_and_print(line);
  }
  free(line);
}

void tokenize_and_print(char *str) {
  char *str_copy = strdup(str);
  if (str_copy == NULL) {
    return;
  }

  char *delim = " \n\t\r";
  char *current = str_copy;
  char *token, *saveptr;

  printf("Tokens:\n");
  while ((token = strtok_r(current, delim, &saveptr))) {
    current = NULL;
    printf("%*s%s\n", 2, "", token);
  }

  free(str_copy);
}
