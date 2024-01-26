#include "../include/fdf.h"

void    point_apply_scale(t_points *point, double scale[3]){
    point->cords[X] *= scale[X];
    point->cords[Y] *= scale[Y];
    point->cords[Z] *= scale[Z];
}

void    map_apply_scale(t_map *map, double scale[3]){
    size_t     i;

    i = 0;
    while(i < map->column * map->row){
        point_apply_scale(&map->point[i], scale);
        ++i;
    }
}
