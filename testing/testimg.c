#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

#define WIDTH 1080
#define HEIGHT 520

typedef struct s_image {
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
} t_image;

void put_pixel(t_image *img, int x, int y, int color) {
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

t_image *load_image(void *mlx_ptr, char *path) {
    t_image *img;
    int width, height;

    img = (t_image *)malloc(sizeof(t_image));
    if (!img) {
        perror("Failed to allocate memory for image");
        exit(1);
    }

    img->img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
    if (!img->img) {
        perror("Failed to load image");
        exit(1);
    }

    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);

    return img;
}

int main() {
    void *mlx_ptr;
    void *win_ptr;
    t_image *img;
    int x, y;

    mlx_ptr = mlx_init();
    if (!mlx_ptr) {
        perror("Failed to initialize MiniLibX");
        exit(1);
    }

    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Image Viewer");
    if (!win_ptr) {
        perror("Failed to create window");
        exit(1);
    }

    img = load_image(mlx_ptr, "../img/img.xpm");

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            put_pixel(img, x, y, *(unsigned int *)(img->addr + (y * img->line_length + x * (img->bpp / 8))));
        }
    }

    mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 0, 0);
    mlx_loop(mlx_ptr);

    return 0;
}
