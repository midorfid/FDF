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

int parse_color_num(char *cell, int *color, int *height){
    char    *num;
    char    *map_color;
    int     res;
    int     color_len;
    int     height_len;

    res = 0;
    map_color = ft_strchr(cell, ',');
    *color = 0xFFFFFF;
    if(map_color == NULL)
        return(ft_atoi_save(cell, height));
    num = alloc_or_perror(ft_strndup(cell, (size_t)map_color - (size_t)cell));
    height_len = ft_atoi_save(num, height);
    color_len = ft_atoi_save(map_color + 1, color);
    if(color_len < 0 || height_len < 0)
        res = -1;
    if(color_len <= 6){
        *color = *color << 8;
        *color |= 0xFF;
    }
    free(num);
    return(res);
}

int parse_line(int fd, t_map *map){
    char    **row;
    size_t  i;
    int     color;
    int     height;
    
    row = get_row(fd);
    if(!row)
        return(1);
    if(!row[0])
        error_msg_exit("line is empty", EXIT_FAILURE);
    i = 0;
    while(row[i]){

        if(map->column != 0 && i > map->column)
            error_msg_exit("row is too long", EXIT_FAILURE);
        if(parse_color_num(row[i], &color, &height) < 0)
            error_msg_exit("invalid number", EXIT_FAILURE);
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
        if(parse_line(fd, map))
            break;
        map->row++;
    }
    return(map);
}
