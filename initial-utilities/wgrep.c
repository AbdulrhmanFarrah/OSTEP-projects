#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define READ_ONLY "r"

void process_file(FILE *filePointer, const char *word);

int main(int argc, char *argv[]) {

  if (argc <= 1) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }

  const char *word = argv[1];

  if (argc == 2) {
    process_file(stdin, word);
    return 0;
  }

  for (int index = 2; index < argc; ++index) {
    FILE *filePointer = fopen(argv[index], READ_ONLY);

    if (filePointer == NULL) {
      printf("wgrep: cannot open file\n");
      exit(1);
    }

    process_file(filePointer, word);

    if (fclose(filePointer) == -1) {
      printf("wgrep: cannot close file\n");
      exit(1);
    }
  }
  
  return 0;
}

void process_file(FILE *filePointer, const char *word) {
  char *line = NULL;
  size_t buffer_size = 0;

  while (getline(&line, &buffer_size, filePointer) != -1) {
    if (strstr(line, word) != NULL) {
      printf("%s", line);
    }
  }
  
  free(line);
}
