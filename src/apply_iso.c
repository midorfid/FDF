#include "../include/fdf.h"

void    point_apply_iso(t_points *point){
    double  x;
    double  y;

    x = (point->cords[X] - point->cords[Y]) * cos(0.523598776);
    y = (-point->cords[Z] + point->cords[X] + point->cords[Y]) \
             * sin(0.523598776);
    point->cords[X] = x;
    point->cords[Y] = y;
    point->cords[Z] = 0;
}

void    map_apply_iso(t_map *map){
    size_t  i;

    i = 0;
    while(i < map->column * map->row){
        point_apply_iso(&map->point[i]);
        ++i;
    }
}
