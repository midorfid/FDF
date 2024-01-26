#include "../include/fdf.h"

int possible_on_screen(mlx_image_t *img, t_points p1, t_points p2){
    const double    pnt1[2] = {p1.cords[X], p1.cords[Y]};
    const double    pnt2[2] = {p2.cords[X], p2.cords[Y]};

    if((pnt1[X] < 0 && pnt2[X] < 0) || (pnt1[Y] < 0 && pnt2[Y] < 0))
        return(0);
    if(pnt1[X] >= img->width && pnt2[X] >= img->width)
        return(0);
    if(pnt1[Y] >= img->height && pnt2[Y] >= img->height)
        return(0);
    return(1);
}

void    draw_point(int x, int y, int color, void *data){
    mlx_image_t *img;

    img = data;
    if(x >= 0 && (uint32_t)x < img->width && y >= 0 && y < img->height)
        mlx_put_pixel(img, x, y, color);
    (void)color;
}

void    plot_point(mlx_image_t *img, t_map *map){
    draw_point(map->point[0].cords[X], map->point[0].cords[Y], \
            map->point[0].color, img);
}

void plot_img(mlx_image_t *img, t_map *map){
    t_points    p1;
    t_points    p2;
    size_t      i;

    i = 0;
    while(i < map->column * map->row){
        p1 = map->point[i];
        if(i % map->column + 1 < map->column){
            p2 = map->point[i + 1];
            if(possible_on_screen(img, p1, p2))
                draw_line(p1, p2, draw_point, img);
        }
        if(i / map->column + 1 < map->row){
            p2 = map->point[i + map->column];
            if(possible_on_screen(img, p1, p2))
                draw_line(p1, p2, draw_point, img);
        }
        ++i;
    }
}
