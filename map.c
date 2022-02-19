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