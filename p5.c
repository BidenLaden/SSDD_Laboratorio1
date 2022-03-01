/*
Modifique los programas anteriores (el nuevo programa será p5.c) de forma que los
argumentos pasados en la línea de mandatos se almacenen en una lista enlazada. En cada elemento de la
lista se almacenará el valor numérico y el valor como cadena de caracteres.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct snodo{ //snodo es el nombre de la estructura
    char* valor;
    struct snodo *sig; //El puntero siguiente para recorrer la lista enlazada
}tnodo; //tnodo es el tipo de dato para declarar la estructura
 
typedef tnodo *tpuntero; //Puntero al tipo de dato tnodo para no utilizar punteros de punteros
 
void insertarEnLista (tpuntero *cabeza, char* e);
void imprimirLista (tpuntero cabeza);
void borrarLista (tpuntero *cabeza);
 
int main(int argc, char* argv[]){
    char* e;
    tpuntero cabeza; //Indica la cabeza de la lista enlazada, si la perdemos no podremos acceder a la lista
    cabeza = NULL; //Se inicializa la cabeza como NULL ya que no hay ningun nodo cargado en la lista
     
    char **x; //Es un puntero de punteros!! (cada argumento es un array tambien)
    printf("Cantidad de valores del array %d\n", argc);
    x = (char **)malloc((argc-1)*sizeof(char*));
    for(int i=0; i< argc-1; i++){
        printf("Argumento %d: %s\n", i+1, argv[i+1]);
        x[i] = (char*)malloc(strlen(argv[i+1] + 1));
        //Usamos strlen en vez de sizeof porque strlen devuelve el numero de caracteres de la cadena
        //y sizeof solo lo que ocupa argv[i+1], hay que sumarle 1 para el codigo 0 que indica el finalde la cadena
        strcpy(x[i], argv[i+1]);
        insertarEnLista (&cabeza, x[i]);
    }
    
     
    printf ("\nSe imprime la lista cargada: ");
    imprimirLista (cabeza);
     
    printf ("\nSe borra la lista cargada\n");
    borrarLista (&cabeza);
     
    printf ("\n");
    
    for(int j=0; j< argc-1; j++){
        free(x[j]);
    }
    free(x);

return 0;
}
 
 
void insertarEnLista (tpuntero *cabeza, char* e){
    tpuntero nuevo; //Creamos un nuevo nodo
    nuevo = malloc(sizeof(tnodo)); //Utilizamos malloc para reservar memoria para ese nodo
    nuevo->valor = e; //Le asignamos el valor ingresado por pantalla a ese nodo
    nuevo->sig = *cabeza; //Le asignamos al siguiente el valor de cabeza
    *cabeza = nuevo; //Cabeza pasa a ser el ultimo nodo agregado
}
 
void imprimirLista(tpuntero cabeza){
    while(cabeza != NULL){ //Mientras cabeza no sea NULL
        printf("%s ",cabeza->valor); //Imprimimos el valor del nodo
        cabeza = cabeza->sig; //Pasamos al siguiente nodo
    }
}
 
void borrarLista(tpuntero *cabeza){ 
    tpuntero actual; //Puntero auxiliar para eliminar correctamente la lista
  
    while(*cabeza != NULL){ //Mientras cabeza no sea NULL
        actual = *cabeza; //Actual toma el valor de cabeza
        *cabeza = (*cabeza)->sig; //Cabeza avanza 1 posicion en la lista
        free(actual); //Se libera la memoria de la posicion de Actual (el primer nodo), y cabeza queda apuntando al que ahora es el primero
    }
}