#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];

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
                token[strlen(token) - 1] = '\0'; // Rimuovi il segno di punteggiatura dalla parola
            }
            
            // Ottieni la prossima parola
            token = strtok(NULL, " \t\n");
        }
    }

    // Chiudi il file
    fclose(file);

    return 0;
}
