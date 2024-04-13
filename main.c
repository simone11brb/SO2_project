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

    // Stampa le parole
    for (int i = 0; i < numWords; i++) {
        printf("%s\n", stringArray[i]);
    }

    // Deallocazione della memoria
    for (int i = 0; i < numWords; i++) {
        free(stringArray[i]);
    }
    free(stringArray);

    fclose(file);

    return 0;
}
