#include "../include/fdf.h"
#include <limits.h>

int ft_atoi_sub16(char c){
    c = ft_tolower(c);
    if(c >= '0' && c <= '9')
        return(c - '0');
    if(c >= 'a' && c <= 'f')
        return(c -'a' + 10);
    return(-1);
}

int ft_atoi_save16(const char *str, int *num){
    long    res;
    int     len;

    len = 0;
    res = 0;
    while(ft_atoi_sub16(*str) >= 0){
        res = res * 16 + ft_atoi_sub16(*str);
        if (res > (long)UINT_MAX)
            return(-1);
        str++;
        len++;
    }
    if(*str != '\0')
        return(-1);
    *num = res;
    return(len);
}

int ft_atoi_save10(const char *str, int *num, int sign){
    long    res;
    int     len;

    len = 0;
    res = 0;
    while(ft_isdigit(*str)){
        res = res * 10 + (*str - '0');
        if((sign == -1 && res > (long)INT_MAX + 1) || res > INT_MAX)
            return(-1);
        str++;
        len++;
    }
    if(*str != '\0')
        return(-1);
    res *= sign;
    *num = res;
    return(len);
}

int ft_atoi_save(const char *str, int *num){
    int     sign;

    if(ft_strncmp(str,"0x", 2) == 0)
        return(ft_atoi_save16(str + 2, num));
    sign = 1;
    if(*str == '-'){
        sign = -1;
        str++;
    }
    else if(*str == '+')
        str++;
    return(ft_atoi_save10(str, num, sign));
}
