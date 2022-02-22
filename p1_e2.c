#include "map.h"

#define N_ROWS 3
#define N_COLS 4

#define Y_INPUT 1
#define X_INPUT 1
#define Y_OUTPUT 2
#define X_OUTPUT 1

int main (){
    Map *maps; 
    Point *x;
    int i, j;

    // Punto 1: Inicialización
    if ((maps = map_new(N_ROWS,N_COLS))==NULL){     //Prueba de errores
        printf("Run failed\n");
        return 1;
    }
    printf("Map:\n%d, %d\n", N_ROWS, N_COLS);

    // Punto 2: Inserción del laberinto
    for(i=0; i<N_ROWS; i++){
        for (j=0; j<N_COLS; j++){
            if (map_insertPoint(maps, point_new(i,j,BARRIER)) == NULL){     // Formación del mapa
                printf("Run failed\n");                                     // Prueba de errores y liberación de memoria
                map_free(maps);
                return 1;
            }
        }
    }

    // Inserción de input y output
    if ((map_insertPoint(maps, point_new(Y_INPUT, X_INPUT, INPUT)) == NULL) || (map_insertPoint(maps, point_new(Y_OUTPUT, X_OUTPUT, OUTPUT)) == NULL)){
        printf("Run failed\n");     
        map_free(maps);                 // Prueba de errores y liberación de memoria
        return 1;
    }

    // Punto 3: Impresión del mapa
    if (map_print(stdout,maps) == -1){
        printf("Run failed\n");
        map_free(maps);
        return 1;
    }

    // Punto 4: Vecinos del output
    printf("Get output neighboors:\n");
    if ((x = point_new(Y_OUTPUT, X_OUTPUT, OUTPUT)) == NULL){
        printf("Run failed\n");
        map_free(maps);
        return 1;
    }

    if (                                                                    // Prueba de errores
        (point_print(stdout, map_getNeighboor(maps, x, RIGHT)) == -1) ||
        (point_print(stdout, map_getNeighboor(maps, x, UP)) == -1) ||
        (point_print(stdout, map_getNeighboor(maps, x, LEFT)) == -1) ||
        (point_print(stdout, map_getNeighboor(maps, x, DOWN)) == -1))
    {
        printf("Run failed\n");
        point_free(x);
        map_free(maps);
        return 1;
    }

    point_free(x);                  // Liberación final de memoria
    map_free(maps);
    
    return 0;
}