void print_array(char list[][50]){
    int lunghezza = sizeof(list)/sizeof(list[0]);
    for(int i = 0; i< lunghezza; i++){
        printf("%s\n", list[i]);
    }
}