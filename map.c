#include "map.h"

#define MAX_NCOLS 64            // Maximun map cols
#define MAX_NROWS 64            // Maximun map rows
#define MAX_BUFFER 64           // Maximun file line size

struct _Map
{
    unsigned int nrows, ncols;

    Point *array[MAX_NROWS][MAX_NCOLS];     // array with the Map points
    Point *input, *output;                  // points input/output
};

/* Implementar funciones declaradas en map.h */
/* Incluir funciones privadas que veamos necesarias */

Map * map_new (unsigned int nrows,  unsigned int ncols){
    int i, j;
    Map *map = NULL;
    if ((map = (Map*) malloc (sizeof(Map))) == NULL){
        return NULL;
    }

    if ((nrows < 0 || nrows >= MAX_NROWS)||(ncols < 0 || ncols >= MAX_NCOLS)){
        return NULL;
    }

    /* Asignación del numero de filas y columnas */
    map->nrows = nrows;
    map->ncols = ncols;

    /* Inicialización del resto de variables */
    for (i=0; i<MAX_NROWS; i++){
        for (j=0; j<MAX_NCOLS; j++){
            map->array[i][j]=NULL;
        }
    }
    map->input = NULL;
    map->output = NULL;

    return map;
}

void map_free (Map *);

Point *map_insertPoint (Map *mp, Point *p);

int map_getNcols (const Map *mp){
    if (mp == NULL){
        return -1;
    }
    return mp->ncols;
}

int map_getNrows (const Map *mp){
    if (mp == NULL){
        return -1;
    }
    return mp->nrows;
}

Point *map_getNeighboor(const Map *mp, const Point *p, Position pos){
    
}