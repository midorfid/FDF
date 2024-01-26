#include "../include/fdf.h"

void    point_apply_offset(t_points *point, double offset[]){
    point->cords[X] += offset[X];
    point->cords[Y] += offset[Y];
    point->cords[Z] += offset[Z];
}

void    map_apply_offset(t_map *map, double offset[]){
    size_t  i;

    i = 0;
    while(i < map->column * map->row){
        point_apply_offset(&map->point[i], offset);
        ++i;
    }
}