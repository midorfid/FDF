#include "../include/fdf.h"

void    error_msg_exit(char *error, int error_code){
    print_error(error);
    exit(error_code);
}

void    print_error(char *error){
    ft_putstr_fd("fdf: ", STDERR_FILENO);
    ft_putendl_fd(error, STDERR_FILENO);
}

void    *alloc_or_perror(void *ptr){
    if(ptr != NULL)
        return(ptr);
    perror_exit("fdf", 1);
}

void    exit_if_true(bool status){
    if(status)
        return(perror_exit("fdf", 1));
    return ;
}

void    perror_exit(const char *s, int error_msg){
    perror(s);
    exit(error_msg);
}
