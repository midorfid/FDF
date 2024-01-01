#include "../include/fdf.h"

void add_point(t_points **points, t_points point){
    static size_t   len;
    static size_t   used_len;
    static t_points *last;
    static size_t   buff = 1;

    if(*points == NULL){
        len = 0;
        used_len = 0;
        *points = alloc_or_perror(calloc(buff, sizeof(t_points)));
        last = *points;
    }
    if(used_len >= buff){
        buff = len;
        *points = ft_realloc(*points, buff * sizeof(t_points), \
                (buff + len) * sizeof(t_points));
        used_len = 0;
        last = &(*points)[len];
    }
    *last = point;
    last++;
    len++;
    used_len++;
}

int parse_color_num(){

}

char    **get_row(int fd){
    char *line;
    char **trimmed;

    line = get_next_line(fd);
    if(!line)
        return(line);
    trimmed = alloc_or_perror(ft_split(line, " "));
    free(line);
    return(trimmed);
}

int parse_line(int fd, t_map *map){
    char    **row;
    size_t  i;
    int     color = 0xFFFFFF;
    int     height;
    
    row = get_row(fd);
    if(!row)
        return(1);
    if(!row[0])
        //print error then exit
    i = 0;
    while(row[i]){

        if(map->column != 0 && i > map->column)
            //row too long
        if(parse_color_num())
            //invalid num
        add_point(&map->point, (t_points){.cords = \
                {i, map->row, height}, .color = color});
        ++i;
    }
    free_row(row, i);
    map->column = i;
    return(0);
}

t_map *parse_map(char *filename){
    int     fd;
    t_map   *map;

    fd = open(filename, O_RDONLY);
    if(fd < 0){
        perror("fdf");
        exit(EXIT_FAILURE);
    }
    while(1){
        if(parse_line())
            break;
        map->row++;
    }
    return(map);
}
