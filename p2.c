/*Modifique el programa anterior (el nuevo programa será p2.c ) asumiendo que los argumentos
que se pasan son todos números enteros. El programa debe convertir cada argumento de entrada, cuyo
formato es una cadena de caracteres, a un número entero. Para convertir una cadena a un número entero
se puede utilizar la función de biblioteca atoi:
    int atoi(const char *nptr);

Esta función convierte la cadena apuntada por nptr a su valor entero correspondiente. El problema de
esta función es que no detecta errores (por ejemplo, cuando se intenta convertir una cadena que no
representa un número entero), así que en su lugar podemos utilizar mejor la función equivalente:
    char *end;
    strtol(nptr, &end, 10);
En caso de que la conversión no se haya podido realizar, el puntero end y nptr tendrán el mismo valor, es
decir:
    if (nptr == end) {
        // error en la conversión
    }*/

#include <stdio.h>
#include <stdlib.h>

/*Con atoi, el problema es que no detecta errores, un string lo imprime como 0.

int main(int argc, char* argv[]){

    for(int i=0; i< argc-1; i++){
        int numero = atoi(argv[i+1]);
        printf("Argumento %d: %d\n", i+1, numero);
    }
}*/

//Con strtol
int main(int argc, char* argv[]){
    char *end;
    for(int i=0; i< argc-1; i++){
        int numero = strtol(argv[i+1], &end, 10); //El 10 es que se convierte a base 10
        if(*end != '\0'){
            printf("Error en la conversion\n");
            break;
        }
        printf("Argumento %d: %d\n", i+1, numero);
    }
    return 0;
}