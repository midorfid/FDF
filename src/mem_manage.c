#include "../include/fdf.h"

void    free_row(char **row, size_t len){
    while (len)
        free(row[(len)--]);
    free(row[0]);
    free(row);
}

void    *ft_realloc(void *old, size_t oldsize, size_t newsize){
    void *res;
    res = malloc(newsize);
    if(!res){
        free(old);
        return(res);
    }
    ft_memcpy(res, old, oldsize);
    free(old);
    return(res);
}