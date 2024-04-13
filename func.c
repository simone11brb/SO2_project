#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "func.h"
#define MAX_LENGTH 100


int countWords(FILE *file) {
    int count = 0;
    char word[MAX_LENGTH];

    // Leggi ogni parola dal file
    while (fscanf(file, "%s", word) != EOF) {
        // Se l'ultimo carattere della parola è un segno di punteggiatura, conta come una parola
        if (isPunctuation(word[strlen(word) - 1])) {
            count++;
        }
        count++;
    }
    rewind(file);
    return count;
}

int isPunctuation(char c) {
    return ispunct(c) && c != '\'';
}

char** createStringArrayFromFile(FILE *file, int numWords) {
    char** list = (char**)malloc(numWords * sizeof(char*));
    if (list == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria.\n");
        exit(1);
    }

    // Allocazione della memoria per ogni stringa nell'array
    for (int i = 0; i < numWords; i++) {
        list[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
        if (list[i] == NULL) {
            fprintf(stderr, "Errore di allocazione della memoria.\n");
            exit(1);
        }
    }

    char line[MAX_LENGTH];
    int index = 0;

    // Leggi le righe finché non raggiungi la fine del file
    while (fgets(line, sizeof(line), file)) {
        // Tokenizza la riga per parole
        char *token = strtok(line, " \t\n");

        // Leggi tutte le parole nella riga
        while (token != NULL) {
            // Verifica se l'ultimo carattere è un segno di punteggiatura
            char last_char = token[strlen(token) - 1];
            if (isPunctuation(last_char) && last_char != '\'') {
                strncpy(list[index], token, strlen(token)-1);
                index++;
                // Se è un segno di punteggiatura diverso dall'apostrofo,
                // copialo nell'array list
                list[index][0] = last_char;
                list[index][1] = '\0'; // Assicurati che il carattere di punteggiatura sia seguito dal terminatore NULL
                ++index;
            } else {
                // Altrimenti, memorizza la parola nell'array list
                strcpy(list[index], token);
                ++index;
            }
            // Ottieni la prossima parola
            token = strtok(NULL, " \t\n");
        }
    }

    return list;
}