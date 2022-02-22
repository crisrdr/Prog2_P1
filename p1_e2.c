#include "map.c"

int main (){
    Map *maps; 
    maps = (Map*) malloc (12*sizeof(Map*));
    printf("Map:\n");
    maps = map_new(4,3);

    map_insertPoint(maps, point_new(0,0,BARRIER));
    map_insertPoint(maps, point_new(0,1,BARRIER));   
    map_insertPoint(maps, point_new(0,2,BARRIER));
    map_insertPoint(maps, point_new(1,0,BARRIER));
    map_insertPoint(maps, point_new(1,1,INPUT));
    map_insertPoint(maps, point_new(1,2,BARRIER));
    map_insertPoint(maps, point_new(2,0,BARRIER));
    map_insertPoint(maps, point_new(2,1,OUTPUT));
    map_insertPoint(maps, point_new(2,2,BARRIER));
    map_insertPoint(maps, point_new(3,0,BARRIER));
    map_insertPoint(maps, point_new(3,1,BARRIER));
    map_insertPoint(maps, point_new(3,2,BARRIER));

    map_print(stdout,maps);

    printf("Get output neighboors:\n");
    Point *x = point_new(2,1,OUTPUT);

    point_print(stdout, map_getNeighboor(maps,x, RIGHT));
    point_print(stdout, map_getNeighboor(maps,x, UP));
    point_print(stdout, map_getNeighboor(maps,x, LEFT));
    point_print(stdout, map_getNeighboor(maps,x, DOWN));


    return 0;
}