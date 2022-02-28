/*
Para probar la función crea el programa p1_e3.c que reciba 
como argumento el nombre de un fichero de texto, cree un 
Map de acuerdo a la descripción contenida en ese fichero, 
imprima el mapa por pantalla e imprima por pantalla los 
vecinos del punto output y los de la esquina inferior 
derecha del mapa.
La ejecución de este programa debefuncionar sin problemas, 
incluyendo una gestión adecuada de la memoria (valgrind no 
debería mostrar fugas ni errores). A continuación se muestra 
la salida del programa cuando se ejecuta en la terminal el
comando:
*/
#include "map.h"

int main(int argc, char *argv[]){
    Map *map=NULL;
    FILE *f;

    if (argc != 2){
        fprintf(stdout,"Arguments missing\n");
        return 1;
    }

    if ((f = fopen(argv[1], "r"))==NULL){   /* Argumento en posicion 1, nombre del fichero de texto */
        fprintf(stdout,"Opening file failed\n");
        return 1;
    }

    if ((map = map_readFromFile(f))==NULL){ /* Creación del mapa a partir del fichero */
        fclose(f);
        return 1;
    }

    if ((map_print(stdout,map))==-1){       /* Impresión del mapa por pantalla */
        map_free(map);
        fprintf(stdout,"Run failed\n");
        return 1;
    }

    


    map_free(map);
    fclose(f);

    return 0;
}