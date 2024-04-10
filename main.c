#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "func.h"

#define MAX_WORD_LENGTH 100

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char list[100][50]; // Array di array di caratteri
    int index = 0;

    // Apri il file in modalità lettura
    file = fopen("input_file.txt", "r");
    if (file == NULL) {
        perror("Impossibile aprire il file");
        return 1;
    }

    // Leggi le righe finché non raggiungi la fine del file
    while (fgets(line, sizeof(line), file)) {
        // Tokenizza la riga per parole
        char *token = strtok(line, " \t\n");

        // Leggi tutte le parole nella riga
        while (token != NULL) {
            // Verifica se l'ultimo carattere è un segno di punteggiatura
            char last_char = token[strlen(token) - 1];
            if (ispunct(last_char) && last_char != '\'') {
                // Se è un segno di punteggiatura diverso dall'apostrofo,
                // stampalo come carattere separato
                list[index][0] = last_char;
                list[index][1] = '\0'; // Assicurati che il carattere di punteggiatura sia seguito dal terminatore NULL
                // Rimuovi il segno di punteggiatura dalla parola
                token[strlen(token) - 1] = '\0';
                ++index;
            }
            // Memorizza la parola nell'array list
            strcpy(list[index], token);
            ++index;

            // Ottieni la prossima parola
            token = strtok(NULL, " \t\n");
        }
    }

    // Chiudi il file
    fclose(file);

    int lunghezza = sizeof(list)/sizeof(list[0]);
    for(int i = 0; i< lunghezza; i++){
        printf("%s\n", list[i]);
    }

    return 0;
}
