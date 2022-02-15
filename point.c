#include "point.h"

struct _Point {
    int x, y;
    char symbol;

    Bool visited; // for DFS
};

Point * point_new (int x, int y, char symbol){
    Point *puntero;
    if ((puntero = (Point *) malloc (sizeof(Point))) == NULL)
        return NULL;    

    puntero->x = x;
    puntero->y = y;
    puntero->symbol = symbol;
    puntero->visited = FALSE;

    return puntero;
}

void point_free (Point *p){
    free(p);
}

int point_getCoordinateX (const Point *p){
    if (p==NULL)
        return __INT_MAX__;
    else return p->x;
}

int point_getCoordinateY (const Point *p){
    if (p==NULL)
        return __INT_MAX__;
    else return p->y;
}

char point_getSymbol (const Point *p){
    if (p==NULL)
        return ERRORCHAR;
    else return p->symbol;
}

Status point_setCoordinateX (Point *p, int x){
    if (x<0)
        return ERROR;
    p->x=x;
    return OK;
}

Status point_setCoordinateY (Point *p, int y){
    if (y<0)
        return ERROR;
    p->y=y;
    return OK;
}

Status  point_setSymbol (Point *p, char c){
    if (c!=INPUT && c!=OUTPUT && c!=BARRIER && c!=SPACE)
        return ERROR;
    p->symbol=c;
    return OK;
}

Point *point_hardcpy (const Point *src){
    Point *p = point_new(src->x, src->y, src->symbol);
    
    return p;
}

Bool point_equal (const void *p1, const void *p2){
    Point *_p1 = (Point *) p1;
    Point *_p2 = (Point *) p2;
    if ((_p1->x ==_p2->x) && (_p1->y ==_p2->y) && (_p1->symbol ==_p2->symbol) )
        return TRUE;    
    else 
        return FALSE;
}

int point_print (FILE *pf, const void *p){
    int nChar;
    Point *pAux = (Point*)p;

    if (pf == NULL || p == NULL){
        return -1;
    }    

    nChar = fprintf (pf, "[(%d, %d): %c]", point_getCoordinateX(pAux), point_getCoordinateY(pAux), point_getSymbol(pAux));

    return nChar;
} // Print Stack
