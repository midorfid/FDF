#include "../include/fdf.h"

double  fdf_smallest(double a, double b){
    return(a < b ? a : b);
}

void    init_mlx(int w_height, int w_width, char *window_name, t_fdf *fdf){
    fdf->mlx = alloc_or_perror(mlx_init(w_width, w_height, window_name, true));
    fdf->img[0] = alloc_or_perror(mlx_new_image(fdf->mlx, w_width, w_height));
    fdf->img[1] = alloc_or_perror(mlx_new_image(fdf->mlx, w_width, w_height));
    fdf->img_idx[0] = mlx_image_to_window(fdf->mlx, fdf->img[0], 0, 0);
    fdf->img_idx[1] = mlx_image_to_window(fdf->mlx, fdf->img[1], 0, 0);
    exit_if_true(fdf->img_idx[0] < 0 || fdf->img_idx[1] < 0);
    mlx_set_instance_depth(&fdf->img[1]->instances[fdf->img_idx[1]], 1);
    exit_if_true(!mlx_loop_hook(fdf->mlx, loop_hook, fdf));
    mlx_resize_hook(fdf->mlx, resize_hook, fdf);
    mlx_key_hook(fdf->mlx, key_hook, fdf);
    fdf->text_img[0] = alloc_or_perror(mlx_put_string(fdf->mlx, "W,A,S,D  =  MOVE", 10, 10));
    fdf->text_img[1] = alloc_or_perror(mlx_put_string(fdf->mlx, "Z,X  =  ZOOM", 10, 40));
    fdf->text_img[2] = alloc_or_perror(mlx_put_string(fdf->mlx, "P  =  PROJECTION", 10, 70));
    fdf->text_img[3] = alloc_or_perror(mlx_put_string(fdf->mlx, "C,V  =  Z-SCALE", 10, 100));
}

t_fdf   *init_fdf(int w_height, int w_width, char *filename){
    t_fdf   *fdf;
    char    *window_name;

    fdf = alloc_or_perror(ft_calloc(1, sizeof(t_fdf)));
    fdf->map = parse_map(filename);
    fdf->update = 1;
    fdf->z_scale = 0.5;
    fdf->map_scale = fdf_smallest((double)w_height / 2 / fdf->map->column, (double)w_width / 2 / fdf->map->row);
    fdf->scale = fdf->map_scale;
    window_name = alloc_or_perror(ft_strjoin("fdf: ",filename));
    init_mlx(w_height, w_width, window_name, fdf);
    free(window_name);
    return(fdf);
}

void    destroy_fdf(t_fdf *fdf){
    destroy_map(fdf->map);
    mlx_delete_image(fdf->mlx, fdf->img[0]);
    mlx_delete_image(fdf->mlx, fdf->img[1]);
    mlx_delete_image(fdf->mlx, fdf->text_img[0]);
    mlx_delete_image(fdf->mlx, fdf->text_img[1]);
    mlx_delete_image(fdf->mlx, fdf->text_img[2]);
    mlx_delete_image(fdf->mlx, fdf->text_img[3]);
    mlx_terminate(fdf->mlx);
    free(fdf);
}