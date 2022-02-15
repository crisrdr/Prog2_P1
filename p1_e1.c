#include "point.h"

void fail_function (Point *x, Point *y){
    printf("Run failed\n");
        point_free (x);
        point_free (y);
}

int main(){
    int i, j;
    char c;
    // Punto 1: Array de 4 punteros
    Point *p[4];

    // Punto 2: Inicialización de los dos primeros puntos
    if ((p[0] = point_new (0, 0, BARRIER)) == NULL){          // Comprobación de la salida de la función
        printf("Run failed\n");
        return 1;
    }
    if ((p[1] = point_new (0, 1, BARRIER)) == NULL){
        printf("Run failed\n");
        point_free (p[0]);
        return 1;
    }

    // Punto 3: Impresión de puntos
    if (point_print (stdout, p[0]) == -1){
        fail_function (p[0],p[1]);
        return 1;
    }
    if (point_print (stdout, p[1]) == -1){
        fail_function (p[0],p[1]);
        return 1;
    }
    printf("\n");

    // Punto 4: Comparación de puntos
    printf("Equal points p[0] and p[1]? ");
    if (point_equal(p[0],p[1]) == TRUE)
        printf("Yes\n");
    else printf("No\n");
    

    // Punto 5: Asignación al tercer elemento del primero
    printf("Creating p[2]: ");
    // Primero se obtiene cada elemento del primer punto
    if ((i = point_getCoordinateX(p[0])) == __INT_MAX__){
        fail_function (p[0],p[1]);
        return 1;
    }
    if ((j = point_getCoordinateY(p[0])) == __INT_MAX__){
        fail_function (p[0],p[1]);
        return 1;
    }
    if ((c = point_getSymbol(p[0])) == ERRORCHAR){
        fail_function (p[0],p[1]);
        return 1;
    }
    // Después se crea un punto en la tercera posición con estos elementos
    if ((p[2] = point_new (i, j, c)) == NULL){
        fail_function (p[0],p[1]);
        return 1;
    }

    // Punto 6: Impresión del tercer punto
    if (point_print (stdout, p[2]) == -1){
        fail_function (p[0],p[1]);
        point_free(p[2]);
        return 1;
    }
    printf("\n");

    // Punto 7: Comparación del primer y el tercer punto
    printf("Equal points p[0] and p[2]? ");
    if (point_equal(p[0],p[2]) == TRUE)
        printf("Yes\n");
    else 
        printf("No\n");

    // Punto 8: Modificación del símbolo de p[2]
    printf("Modifying p[2]: ");
    if ((point_setSymbol(p[2], SPACE)) == ERROR){
        fail_function (p[0],p[1]);
        point_free(p[2]);
        return 1;
    }
    if ((point_print (stdout, p[2])) == -1){
        fail_function (p[0],p[1]);
        point_free(p[2]);
        return 1;
    }
    printf("\n");

    // Punto 9: Comparación del primer y el tercer punto (de nuevo, con el símbolo del tercero cambiado)
    printf("Equal points p[0] and p[2]? ");
    if (point_equal(p[0],p[2]) == TRUE)
        printf("Yes\n");
    else
        printf("No\n");

    // Punto 10: Asignación al cuarto elemento del primero
    printf("Assign p[3] = p[0]\n");
    // Primero se obtiene cada elemento del primer punto
    // Se ha hecho en el punto 5 y almacenado en las variables i, j, c

    // Después se crea un punto en la cuarta posición con estos elementos
    if ((p[3] = point_new (i, j, c)) == NULL){
        fail_function (p[0],p[1]);
        point_free (p[2]);
        return 1;
    }

    // Punto 11: Modificación del símbolo de p[3]
    printf("Modifying p[3]: ");
    if ((point_setSymbol(p[3], OUTPUT)) == ERROR){
        fail_function (p[0],p[1]);
        point_free(p[2]);
        point_free(p[3]);
        return 1;
    }
    if ((point_print (stdout, p[3])) == -1){
        fail_function (p[0], p[1]);
        point_free(p[2]);
        point_free(p[3]);
        return 1;
    }
    printf("\n");

    // Punto 12: Impresión de los 4 puntos
    for (i=0; i<4; i++){
        if ((point_print (stdout, p[i])) == -1){
            fail_function (p[0], p[1]);
            point_free(p[2]);
            point_free(p[3]);
            return 1;
        }
    } 
    printf("\n"); 

    // Liberación final de memoria
    for (i=0; i<4; i++){
        point_free (p[i]);
    }   

    return 0;
}