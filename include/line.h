#include    "fdf.h"

#ifndef LINE_H
# define LINE_H

typedef struct line
{
    int start[2];
    int end[2];
    int delta[2];
    int decision[2];
    int sign[2];
    //color
}t_line;

#endif
