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

typedef struct	s_data 
{
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
int  	number_of_moves;
t_data	*data;
}	t_mlx;


//init
void	handle_init(t_mlx *handle);

// SPRITE
void	exit_draw(t_mlx *handle, int x, int y);
void	sprite_draw(t_mlx *handle, void *sprite, int x, int y);
void	render_exit(t_mlx *handle);

// DRAWING FUCNTIONS
void	mlx_put_pixel_fast(t_data *data, int x, int y, int color);


// FRAME FUNCTIONS render
int		ft_frame(t_mlx *handle);
void	ft_handle_play(t_mlx *handle);

// MOVES
int		ft_bitch_get_d(t_mlx *handle);
int		ft_bitch_get_w(t_mlx *handle);
int		ft_bitch_get_a(t_mlx *handle);
int		ft_bitch_get_s(t_mlx *handle);

// GAME
int 	check_player_on_item(t_mlx *handle, int x, int y);
int 	check_player_on_exit(t_mlx *handle, int x, int y);

// UTIL FUNCTIONS
int		ft_kill(char *str);
size_t	ft_strlen(const char *c);
char 	*ft_itoa(int num);
void	free_all(t_mlx *handle);

// DRAWING FUNCTIONS
int  	put_move_count(t_mlx *handle);


// INPUT FUNCTIONS
int		ft_keyPressed(int keycode, t_mlx *handle);

// map generatoring.
// Read map
char	**read_map(char *path);
void	free_map(char **map);
int		map_checker(t_mlx *handle);
int		render_map(t_mlx *handle);

#endif