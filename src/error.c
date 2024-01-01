#include "../include/fdf.h"

void    alloc_or_perror(void *ptr){
    if(ptr != NULL)
        return(ptr);
    perror_exit("fdf", 1);
}

void    perror_exit(const char *s, int error_msg){
    perror(s);
    exit(error_msg);
}
