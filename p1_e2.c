#include "map.h"

#define N_ROWS 3
#define N_COLS 4

#define Y_INPUT 1
#define X_INPUT 1
#define Y_OUTPUT 2
#define X_OUTPUT 1

int main (){
    Map *maps; 
    Point *x, *y;
    int i, j;

    /* Punto 1: Inicialización */
    if ((maps = map_new(N_COLS,N_ROWS))==NULL){     /* Prueba de errores */
        printf("Run failed\n");
        return 1;
    }

    /* Punto 2: Inserción del laberinto */
    for(i=0; i<N_COLS; i++){
        for (j=0; j<N_ROWS; j++){
            y = point_new(j,i,BARRIER);
            if (i==Y_INPUT && j==X_INPUT){
                if ((x = map_insertPoint(maps, y)) == NULL){      
                    printf("Run failed\n");                                
                    map_free(maps);
                    return 1;
                }
            } else if (i==Y_OUTPUT && j==X_OUTPUT){
                if ((x = map_insertPoint(maps, y)) == NULL){       
                    printf("Run failed\n");                                    
                    map_free(maps);
                    return 1;
                }
            } else {
                if ((x = map_insertPoint(maps, y)) == NULL){      
                    printf("Run failed\n");
                    point_free(y);                                  
                    map_free(maps);
                    return 1;
                }    
            }   
            point_free(y);           
        }
    }
    /* Inserción de input y output 
    if (((x = map_insertPoint(maps, point_new(Y_INPUT, X_INPUT, INPUT))) == NULL) || ((y = map_insertPoint(maps, point_new(Y_OUTPUT, X_OUTPUT, OUTPUT))) == NULL)){
        printf("Run failed\n");   
        point_free(y);
        point_free(x); 
        map_free(maps);                  Prueba de errores y liberación de memoria 
        return 1;
    }
    point_free(y);
    point_free(x); */

    /* Punto 3: Impresión del mapa */
    fprintf(stdout,"Map:\n");
/*                                                      HASTA AQUI TODO BIEN                      */
    if (map_print(stdout,maps) == -1){
        printf("Run failed\n");
        map_free(maps);
        return 1;
    }

    /* Punto 4: Vecinos del output */
    fprintf(stdout,"\nGet output neighboors:\n");
    if ((x = point_new(Y_OUTPUT, X_OUTPUT, OUTPUT)) == NULL){
        printf("Run failed\n");
        point_free(x);
        map_free(maps);
        return 1;
    }

    if (                                                                    /* Prueba de errores */
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

    point_free(x);                  /* Liberación final de memoria */
    map_free(maps);
    
    return 0;
}