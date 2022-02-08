#include "point.h"

struct _Point {
    int x, y;
    char symbol;

    Bool visited; // for DFS
};

/* 
    • Implementar funciones de la interfaz pública declaradas en el fichero point.h.
    • Las funciones privadas que consideres oportunas.
*/