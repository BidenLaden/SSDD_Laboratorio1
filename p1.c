/*Escriba un programa (p1.c) que acepte en la línea de mandatos un número indeterminado de
argumentos. El programa debe imprimir cada argumento en una línea diferente. El argumento se imprimirá
como una cadena de caracteres.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    for(int i=0; i< argc-1; i++){
        printf("Argumento %d: %s\n", (i+1), argv[i+1]);
    }
}