/*
Modifique el programa del ejercicio 3 (el nuevo programa será p6.c) de forma que ordene de
menor a mayor los elementos del array utilizando la función de biblioteca qsort().
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *_a, const void *_b);

int main(int argc, char* argv[]){
    
    int *x;
    printf("Cantidad de valores del array %d\n", argc-1);
    x = (int*)malloc(sizeof(int)*(argc-1));

    char *end;
    for(int i=0; i< argc-1; i++){
        int numero = strtol(argv[i+1], &end, 10); //El 10 es que se convierte a base 10
        if(*end != '\0'){
            printf("Error en la conversion\n");
            break;
        }
        printf("Argumento %d: %d\n", i+1, numero);
        x[i] = numero;
    }

    qsort(x,argc-1,sizeof(int),&compare);
    
    for(int j=0; j< argc-1; j++){
        printf("%d ", x[j]);
    }
    printf("\n");

    free(x);
    return 0;
}

int compare(const void *_a, const void *_b) {
    int *a, *b;    
    a = (int *) _a;
    b = (int *) _b;
        
    return (*a - *b);
}