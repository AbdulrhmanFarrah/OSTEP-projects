/*
    I have struggled a lot in this program, so after long time of sufferring 
    I gave the code to gemini and it gave me what I need exactly was (fputc), (fgetc)

    also I was thinking in performence of keep asking for I/O for every character
    is gonna make the performence terrible, so I thought of buffer then I saw
    that buffer of character so how can I write the (int) frequencyCounter
    I am gonna need another I/O, then I thought about linked list and maintain some size of it
    like a stream or something, after all that I have resigned and asked gemini 
    and it told me that it is not that horrible performence because of the OS like handle 
    the caching and buffering some bytes of the file

    - I think I have hated c because of this program -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // if there is no input files
    if (argc <= 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    int previousCharacter = -1; 
    int currentCharacter;  
    int frequencyCounter = 0;

    for (int index = 1; index < argc; ++index) {
        FILE *file = fopen(argv[index], "r");

        if (file == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while ((currentCharacter = fgetc(file)) != EOF) {
            if (currentCharacter == previousCharacter) {
                frequencyCounter++;
                continue;
            } 
            else if (previousCharacter != -1){
                fwrite(&frequencyCounter, sizeof(int), 1, stdout);
                fputc(previousCharacter, stdout);
            }

            previousCharacter = currentCharacter;
            frequencyCounter = 1;
        }

        if (fclose(file) != 0) {
            printf("wzip: can't close file\n");
            exit(1);
        }
    }   

    if (previousCharacter != -1) {
        fwrite(&frequencyCounter, sizeof(int), 1, stdout);
        fputc(previousCharacter, stdout);
    }

    return 0;
}