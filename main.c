#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "func.h"

#define MAX_WORD_LENGTH 100

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Impossibile aprire il file.\n");
        return 1;
    }

    int numWords = countWords(file);
    printf("Numero di parole nel file: %d\n", numWords);

    char** stringArray = createStringArrayFromFile(file, numWords);
    if (stringArray == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria.\n");
        return 1;
    }

    print_array(stringArray, numWords);
    fclose(file);

    return 0;
}
