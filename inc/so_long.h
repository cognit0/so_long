#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"

typedef struct s_hitbox
{
	int x;
	int y;
}	t_hixbox;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int    	width;
	int    	height;
	t_data	*data;
}	t_mlx;

t_mlx	*handle_init(int width, int height);

// DRAWING FUCNTIONS
int		mlx_drawline_coords(t_mlx *handle, int bx, int dx, int by, int dy, int color);
void	mlx_put_pixel_fast(t_data *data, int x, int y, int color);
int		mlx_check_pixel(t_data *data, int x, int y, int color);

// FRAME FUNCTIONS
int  	ft_frame(t_mlx *handle);
// UTIL FUNCTIONS
int		ft_kill(char *str);
// INPUT FUNCTIONS
int   	ft_keyPressed(int keycode, t_mlx *handle);

#endif