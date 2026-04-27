#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    // if there is no input files
    if (argc <= 1) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int index = 1; index < argc; ++index) {
        FILE *file = fopen(argv[index], "rb");

        if (file == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }
        
        unsigned char numberInBytes[5];

        while (fread(numberInBytes, sizeof(unsigned char), 5, file) == 5) {
            int frequencyCounter;
            memcpy(&frequencyCounter, numberInBytes, sizeof(int));

            char character = numberInBytes[4];
            while (frequencyCounter--) {
                fwrite(&character, sizeof(char), 1, stdout);
            }
        }

        if (fclose(file) != 0) {
            printf("wunzip: can't close file\n");
            exit(1);
        }
    }

    return 0;
}