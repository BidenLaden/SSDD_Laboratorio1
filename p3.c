/*Modifique el programa anterior (el nuevo programa será p3.c) de forma que los argumentos
pasados en la línea de mandatos y convertidos a enteros se almacenen en un array creado de forma
dinámica. El programa debe incluir una función denominada ObtenerMinMax(), que reciba el array y
obtenga el valor mínimo y máximo del array.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int max = 0;
    int min = 1000000;
    int *x;
    printf("Cantidad de valores del array %d\n", argc);
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
    for(int j=0; j< argc-1; j++){
        printf("%d ", x[j]);
    }
    printf("\n");

    ObtenerMinMax(x,argc-1, &min,&max);
    free(x);
    return 0;
}
void ObtenerMinMax(int v[], int numComponentes, int *min, int *max){
    for(int i = 0; i < numComponentes; i++){
        if(v[i] > *max){
            *max = v[i];
        }
        else if(v[i] < *min){
            *min = v[i];
        }
    }
    printf("El minimo es %d\n",*min);
    printf("El maximo es %d\n", *max);
}
