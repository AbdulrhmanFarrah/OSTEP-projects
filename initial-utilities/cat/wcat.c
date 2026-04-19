#include <stdio.h>
#include <stdlib.h>

#define READ_ONLY "r"
#define BUFFER_SIZE 512

char buffer[BUFFER_SIZE];

void printFile(FILE *filePointer) {
  while (fgets(buffer, BUFFER_SIZE, filePointer) != NULL) {
    printf("%s", buffer);
  }
}

int main(int argc, char *argv[]) {
  
  if (argc == 1)
    return 0;
  
  for (int index = 1; index < argc; ++index) {
    FILE *filePointer = fopen(argv[index], READ_ONLY);

    if (filePointer == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }
    
    printFile(filePointer);

    if (fclose(filePointer) != 0) {
      printf("wcat: cannot close file\n");
      exit(1);
    }
  }
  
  return 0;
}
