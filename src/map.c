#include "../include/fdf.h"

t_map *init_map(){
    return(alloc_or_perror(calloc(1, sizeof(t_map))));
}

void    destroy_map(t_map *map){
    free(map->point);
    free(map);
}

t_map *dup_map(t_map *map){
    t_map   *res;
    size_t  points_size;

    res = alloc_or_perror(malloc(sizeof(t_map)));
    ft_memcpy(res, map, sizeof(t_map));
    points_size = map->column * map->row * sizeof(t_points);
    res->point = alloc_or_perror(malloc(points_size));
    ft_memcpy(res->point, map->point, points_size);
    return(res);
}
