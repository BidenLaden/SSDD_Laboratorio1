/*Modifique el programa anterior (el nuevo programa será p4.c) de forma que los argumentos
pasados en la línea de mandatos tratados como cadenas de caracteres se almacenen en un array de forma
dinámica. En este caso se creará un array dinámico de cadenas de caracteres.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    char **x; //Es un puntero de punteros!! (cada argumento es un array tambien)
    printf("Cantidad de valores del array %d\n", argc);
    x = (char **)malloc((argc-1)*sizeof(char*));
    for(int i=0; i< argc-1; i++){
        printf("Argumento %d: %s\n", i+1, argv[i+1]);
        x[i] = (char*)malloc(strlen(argv[i+1] + 1));
        //Usamos strlen en vez de sizeof porque strlen devuelve el numero de caracteres de la cadena
        //y sizeof solo lo que ocupa argv[i+1], hay que sumarle 1 para el codigo 0 que indica el finalde la cadena
        strcpy(x[i], argv[i+1]);
    }
    for(int k=0; k< argc-1;k++){
        printf("%s", x[k]);
    }
    for(int j=0; j< argc-1; j++){
        free(x[j]);
    }
    printf("\n");
    free(x);
    return 0;
}