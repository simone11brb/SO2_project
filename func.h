#include<stdio.h>
//char readFile(char *file_path); //dichiarazione funzione readFile che restituisce un array di stringhe
void print_array(char **stringArray, int numWords);

int isPunctuation(char c);

int countWords(FILE *file);

char** createStringArrayFromFile(FILE *file, int numWords);