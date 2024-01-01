#include "../include/fdf.h"

t_map *init_map(){
    return(alloc_or_perror(calloc(1, sizeof(t_map))));
}
