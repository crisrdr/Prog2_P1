#include "point.h"

int main(){
    int i;
    // Punto 1
    Point *p[4];

    // Punto 2
    p[0] = point_new ( 0,0, BARRIER);
    p[1] = point_new ( 0,1, BARRIER);

    // Punto 3
    point_print (stdout, p[0]);
    point_print (stdout, p[1]);
    printf("\n");

    // Punto 4
    printf("Equal points p[0] and p[1]? ");
    if (point_equal(p[0],p[1]) == TRUE)
        printf("Yes\n");
    if (point_equal(p[0],p[1]) == FALSE)
        printf("No\n");

    // Punto 5
    p[2]= p[0];

    // Punto 6
    printf("Creating p[2]:");
    point_print (stdout, p[2]);
    printf("\n");

    // Punto 7
    printf("Equal points p[0] and p[2]? ");
    if (point_equal(p[0],p[2]) == TRUE)
        printf("Yes\n");
    else 
        printf("No\n");

    // Punto 8
    printf("Modifying p[2]: ");
    point_setSymbol(p[2], SPACE);
    point_print (stdout, p[2]);
    printf("\n");

    // Punto 9
    printf("Equal points p[0] and p[2]? ");
    if (point_equal(p[0],p[2]) == TRUE)
        printf("Yes\n");
    else
        printf("No\n");

    // Punto 10
    p[3]= p[0];

    // Punto 11
    point_setSymbol(p[3], OUTPUT);

    // Punto 12
    for (i=0; i<4; i++){
        point_print (stdout, p[i]);
    } 
    printf("\n");   

    return 0;
}