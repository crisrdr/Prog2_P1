#include "map.h"

#define MAX_NCOLS 64            /* Maximun map cols */
#define MAX_NROWS 64            /* Maximun map rows */
#define MAX_BUFFER 64           /* Maximun file line size */

struct _Map {
    unsigned int nrows, ncols;

    Point *array[MAX_NROWS][MAX_NCOLS];     /* array with the Map points */
    Point *input, *output;                  /* points input/output */
};

/* Implementar funciones declaradas en map.h */
/* Incluir funciones privadas que veamos necesarias */

Map * map_new (unsigned int nrows,  unsigned int ncols){
    int i, j;
    Map *map = NULL;

    if ((nrows < 0 || nrows >= MAX_NROWS)||(ncols < 0 || ncols >= MAX_NCOLS)){
        return NULL;
    }

    if ((map = (Map*) malloc (sizeof(Map))) == NULL){
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

/*libera la memoria guardada para el graph y sus puntos */
void map_free (Map *g){
    int i, j;

    for(i=0;i<g->nrows;i++)
        for(j=0;j<g->ncols;j++)
            point_free(g->array[j][i]);
            
    g->ncols = '\0';
    g->nrows = '\0';

    point_free(g->input);
    point_free(g->output);

    free(g);      

}

/*inserta un punto en el mapa en las coodenadas indicadas en point*/
Point *map_insertPoint (Map *mp, Point *p){
    if (!p){
        return NULL;
    }

    if ((mp->array[point_getCoordinateY(p)][point_getCoordinateX(p)] = point_hardcpy(p)) == NULL){
        return NULL;
    }
        
        /*
        (point_setSymbol (mp->array[point_getCoordinateY(p)][point_getCoordinateX(p)], point_getSymbol(p)) == ERROR) ||
        (point_setCoordinateX(mp->array[point_getCoordinateY(p)][point_getCoordinateX(p)], point_getCoordinateX(p)) == ERROR) ||
        (point_setCoordinateY(mp->array[point_getCoordinateY(p)][point_getCoordinateX(p)] ,point_getCoordinateY(p)) == ERROR) ||
        (point_setSymbol(mp->array[point_getCoordinateY(p)][point_getCoordinateX(p)] ,point_getSymbol(p)) == ERROR))
    {
        return NULL;
    } */
    
    return p;
}

/*devuelve el numero de columnas*/
int map_getNcols (const Map *mp){
    if (mp == NULL){
        return -1;
    }
    return mp->ncols;
}

/*devuelve el numero de filas*/
int map_getNrows (const Map *mp){
    if (mp == NULL){
        return -1;
    }
    return mp->nrows;
}

/*devuelve el input  */
Point * map_getInput(const Map *mp){
    if (mp == NULL){
        return NULL;
    }
    return mp->input;
    
}     

/*devuelve el output  */
Point * map_getOutput (const Map *mp){
    if (mp == NULL){
        return NULL;
    }
    return mp->output;
}   

/* Devuelve el point con las coordenadas p y null si hay un error */
Point *map_getPoint (const Map *mp, const Point *p){
    if (!mp || p == NULL){
        return NULL;
    }
    else{
        return mp-> array[point_getCoordinateY(p)][point_getCoordinateX(p)];
    }     
}


/*devuelve el punto que esta al lado del punto en la direccion idicada POR p*/
Point *map_getNeighboor(const Map *mp, const Point *p, Position pos){
    if (!mp || p==NULL){
        return NULL;
    }

    switch (pos) {
        case RIGHT:
            return mp-> array[point_getCoordinateY(p)][point_getCoordinateX(p)+1];
            break;
        case UP:
            return mp-> array[point_getCoordinateY(p)-1][point_getCoordinateX(p)];
            break;
        case LEFT:
            return mp-> array[point_getCoordinateY(p)][point_getCoordinateX(p)-1];
            break;
        case DOWN:
            return mp-> array[point_getCoordinateY(p)+1][point_getCoordinateX(p)];
            break;

        default:
            return NULL;
            break;
    }
        
}

Status map_setInput(Map *mp, Point *p){
    if (mp==NULL || p==NULL){
        return ERROR;
    }
    mp->input=p;

    return OK;
}

Status map_setOutput (Map *mp, Point *p){
    if (mp==NULL || p==NULL){
        return ERROR;
    }
    mp->output=p;

    return OK;
}

/* EJERCICIO 3
Map * map_readFromFile (FILE *pf){
    Map *map;
    if (pf==NULL){
        return NULL;
    }
    scanf(pf, "%d %d", map->rows, map->ncols);


}
*/
/*compara dos mapas y devuelve true o false*/
Bool map_equal (const void *_mp1, const void *_mp2){
    int i, j, flag=0;
    Map *mp1 = (Map *) _mp1; 
    Map *mp2 = (Map *) _mp2;
    
    if ((mp1->ncols == mp2->ncols) && (mp1->nrows == mp2->nrows) && (mp1->input == mp2->input) && (mp1->output == mp2->output)){
        for (i=0; i<mp1->nrows; i++){
            for (j=0; j<mp1->ncols; j++){
                if (!(mp1->array[i][j] == mp2->array[i][j]))
                    flag=1;
            }
        }
    }
    if (!flag)
        return TRUE;
    else 
        return FALSE;
}

/*imprime en el archivo el numero de filas y columnas */
int map_print (FILE *pf, Map *mp){
    int i, j, numChar=0;
    if (pf==NULL || mp==NULL){
        return -1;
    }
    fprintf(pf, "%d %d\n", mp->nrows, mp->ncols);
    for(i=0; i<mp->ncols; i++){
        for(j=0; j<mp->nrows; j++){
            if ((numChar += point_print(pf, mp->array[i][j])) == -1){
                return -1;
            }
        }
    }
    return numChar;
}
