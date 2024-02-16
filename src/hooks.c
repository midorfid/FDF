#include "../include/fdf.h"

typedef struct key_pressed
{
    enum keys   key;
    double      delta;
    double      *result;
}t_key_pressed;

void    key_handler(t_fdf *data){
    const t_key_pressed     base[] = \
{
    {MLX_KEY_W, data->y_offset - (5 / data->scale), &data->y_offset},
    {MLX_KEY_A, data->x_offset - (5 / data->scale), &data->x_offset},
    {MLX_KEY_S, data->y_offset + (5 / data->scale), &data->y_offset},
    {MLX_KEY_D, data->x_offset + (5 / data->scale), &data->x_offset},

    {MLX_KEY_Z, data->scale * 1.05, &data->scale},
    {MLX_KEY_X, data->scale * 0.95, &data->scale},
    {MLX_KEY_C, data->z_scale + 0.05, &data->z_scale},
    {MLX_KEY_V, data->z_scale - 0.05, &data->z_scale}
};
    size_t          i;
    t_key_pressed   current;

    i = 0;
    while(i < sizeof(base) / sizeof(t_key_pressed)){
        current = base[i];
        if(mlx_is_key_down(data->mlx, current.key)){
            data->update = 1;
            *current.result = current.delta;
        }
        ++i;
    }
}

void    resize_hook(int32_t width, int32_t height, void *input_data){
    t_fdf   *data;

    data = input_data;
    data->update = 1;
    exit_if_true(!mlx_resize_image(data->img[0], width, height));
    exit_if_true(!mlx_resize_image(data->img[1], width, height));
}

void    key_hook(mlx_key_data_t keydata, void *input_data){
    t_fdf       *data;

    data = input_data;
    if(keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS){
        data->update = 1;
        data->projection = !data->projection;
    }
}

void    loop_hook(void *input_data){
    t_fdf   *data;

    data = input_data;
    if(mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE)){
        mlx_close_window(data->mlx);
        return ;
    }
    key_handler(data);
    if(data->update){
        update_screen(data);
        data->update = 0;
    }
}
