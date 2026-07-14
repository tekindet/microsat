#include "solver.h"

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");

  if (file == NULL) {
    printf("Could not open file %s\n", argv[1]);
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = malloc(size);
  fread(buffer, 1, size, file);

  fclose(file);

  printf("The file size is : %ld\n", size);

  solve(buffer, size);

  free(buffer);
  return 0;
}
