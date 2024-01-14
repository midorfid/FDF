#include    "fdf.h"

#ifndef LINE_H
# define LINE_H

typedef void (*t_plotf)(int, int, int, void *);

typedef struct color
{
    double  current[4];
    double  change[4];
    int     axis;
    int     orginal;
    int     alt;
}t_color;

typedef struct line
{
    int     start[2];
    int     end[2];
    int     delta[2];
    int     error[2];
    int     sign[2];
    t_color color;
}t_line;


#endif
