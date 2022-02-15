#include "point.h"

int main(){
    Point **p[4];  //Array de punteros
    p[0]=  point_new ( 0,0, BARRIER);
    p[1] = point_new ( 0,1, BARRIER);

    point_print (stdout, p[0]);
    point_print (stdout, p[1]);
    printf("\n");
    printf("Equal points p[0] and p[1]?");
    if (point_equal(p[0],p[1]) == TRUE)
        printf("Yes \n");
    else
        Printf("No \n");
    p[3]= p[0];

}