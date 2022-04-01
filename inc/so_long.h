#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "head_data.h"
# include "libft.h"

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
// maping.
	char	**map;
	int		map_width;
	int		map_height;

// validation
	int		exit_obj;
	int		player_obj;
	int		collectable_obj;

// sprite
void	*sprite_back;
void	*sprite_wall;
void	*sprite_collectable;
void	*sprite_exit;
void	*sprite_player;
int		sprite_w;
int		sprite_h;
// player
int		player_x;
int		player_y;
t_data	*data;
}	t_mlx;


//init
void	handle_init(t_mlx *handle);



// DRAWING FUCNTIONS
int		mlx_drawline_coords(t_mlx *handle, int bx, int dx, int by, int dy, int color);
void	mlx_put_pixel_fast(t_data *data, int x, int y, int color);
int		mlx_check_pixel(t_data *data, int x, int y, int color);



// FRAME FUNCTIONS render
int		ft_frame(t_mlx *handle);
void	ft_handle_play(t_mlx *handle);



// UTIL FUNCTIONS
int		ft_kill(char *str);
size_t	ft_strlen(const char *c);



// INPUT FUNCTIONS
int		ft_keyPressed(int keycode, t_mlx *handle);

// map generatoring.
// Read map
char	**read_map(char *path);
void	free_map(char **map);
int		map_checker(t_mlx *handle);
int	render_map(t_mlx *handle);

#endif