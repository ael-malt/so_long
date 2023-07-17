/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:30:32 by ael-malt          #+#    #+#             */
/*   Updated: 2023/07/17 16:35:28 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
// # include "./so_long.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

// Map layout
typedef struct s_lay
{
	int	n_row;
	int	n_col;
	int	n_exit;
	int	n_pl;
	int	n_gh;
	int	n_collect;
}				t_lay;

// Map possible errors
typedef struct s_err
{
	int	inv_rowlen;
	int	inv_char;
	int	inv_n_players;
	int	inv_n_ghosts;
	int	inv_n_collect;
	int	inv_n_exits;
	int	inv_borders;
	int	inv_path;
}				t_err;

// Sprite Size
# define SIZE 32

// Ghost color order:
// (R)ed, (B)lue, Pin(K), (O)range, (G)reen, (Y)ellow, (P)urple
# define COLORS "RBKOGYP"

// Enum for (ST)op, (N)orth, (S)outh, (E)ast, (W)est as ints 
enum e_direction
{
	ST = 0,
	N = 1,
	S = -1,
	E = 2,
	W = -2
};

// Struct to store the sprites for every digit
typedef struct s_font
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	void	*black;
}				t_font;

// Struct containing list of sprites for a given player
typedef struct s_pl_sprite
{
	t_list	*up;
	t_list	*up_bak;
	t_list	*down;
	t_list	*down_bak;
	t_list	*left;
	t_list	*left_bak;
	t_list	*right;
	t_list	*right_bak;
	t_list	*panic;
	t_list	*panic_bak;
}				t_pl_sprite;

// MLX image pointers for the map
typedef struct s_sprite
{
	void		*logo;
	void		**wall;
	void		*pacfood;
	void		*portal;
	void		*pacman;
	void		*pixels;
	void		*black;
	t_list		*pac_dying_bak;
	t_list		*pac_dying;
	t_font		score_font;
}				t_sprite;

// Small list showing if a player can go north, south, east or west
typedef struct s_legal_actions
{
	int	north;
	int	south;
	int	east;
	int	west;
}				t_legal_actions;

// Main Player struct with position and direction (linked list)
typedef struct s_player
{
	t_vector		pos;
	t_vector		win_pos;
	int				dir;
	int				moving;
	t_pl_sprite		sprites;
	t_legal_actions	legal;
	struct s_player	*next;
}				t_player;

// Main attributes for the game
typedef struct s_game
{
	int			width;
	int			height;
	void		*id;
	void		*w_id;
	t_lay		*lay;
	t_lay		lay_bak;
	t_sprite	sprites;
	t_player	*pl;
	t_player	*gh;
	int			next_dir;
	char		**map;
	char		**map_bak;
	int			n_collect_bak;
	int			pac_dying;
	int			panic_mode;
	int			n_frames;
	int			n_moves;
	int			redraw;
	int			g_rate;
}				t_game;

// Check
char		**check_params(int argc, char **argv, t_lay *lay);
char		**check_map(int fd, t_lay *lay);
t_lay		ft_newlayout(void);
int			check_map_path(char **map, t_lay *lay);


// Map
t_err		ft_newmap_error(void);
void		ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str);
int			error_msg(char *msg, char **map_str);
int			ft_print_map_error(t_err *map_err, char **map_str);
void		ft_checklayout(char *line, t_err *map_err, t_lay *lay, int is_last);

// Game
void		init_game(char **map, t_lay lay);
void		ft_newgame(t_game *game, char **map, t_lay *lay);
void		ft_check_game(t_game *game);
int			key_hook(int key, t_game *game);
int			end_game(t_game *game);

// Window
int			close_window(t_game	game);

// Sprites
t_sprite	ft_initsprites(t_game *game);
void		ft_put_map(t_game *game, int x, int y);
int			free_sprites(t_game *game);
void		free_players(t_game *game);

// Anim
t_list		*ft_load_pacdeath(t_game *game);
void		free_animation(t_game *game, t_list *start);
void		ft_anim_pacdeath(t_game *game);

// Anim Dir
void		ft_anim_north(t_game *game, t_player *pl);
void		ft_anim_south(t_game *game, t_player *pl);
void		ft_anim_east(t_game *game, t_player *pl);
void		ft_anim_west(t_game *game, t_player *pl);
void		ft_anim_panic(t_game *game, t_player *pl);

// Score
void		ft_update_score(t_game *game);
void		ft_put_font(t_game *game, int digit, int i);
t_font		ft_load_score_font(t_game *game);
void		free_fonts(t_game *game);

// Player
t_player	*ft_plrnew(t_vector pos);
void		ft_plradd_back(t_player **lst, t_player *newnode);
int			ft_update(t_game *game);
int			ft_checkmvtogh(t_game *games, int dir, t_player *pl);
int			ft_delete_player(t_game *game, t_vector old);

// Player List
void		ft_playerlist(char **map, t_game *game);
void		ft_free_playerlist(t_game *game);
void		ft_free_singlepl(t_game *game, t_player *pl);
int			ft_deletefirst_plr(t_game *game);
int			ft_deletelast_plr(t_game *game);

// Pacman
void		ft_load_pacmans(t_game *game);
void		ft_next_dir(t_game *game);
void		ft_put_pacman(t_game *game);

//Ghosts
void		ft_load_ghosts(t_game *game);
t_list		*ft_chooseghcolor(t_game *game, int i, int dir);
void		ft_put_ghosts(t_game *game);
void		ft_update_ghosts(t_game *game);
void		ft_move_ghost(int dir, t_game *game, t_player *gh);

// Utils
int			ft_euclideandistance(t_vector src, t_vector dest);
void		ft_move(int dir, t_game *game, t_player *temp);
int			ft_swap_tile(t_vector old, t_vector new, t_game *game);
int			ft_reset(t_game *game);
void		ft_newdirection(t_game *game, int direction);

// Load Dir
t_list		*ft_load_north(t_game *game, char *path, int i);
t_list		*ft_load_south(t_game *game, char *path, int i);
t_list		*ft_load_east(t_game *game, char *path, int i);
t_list		*ft_load_west(t_game *game, char *path, int i);
t_list		*ft_load_panic(t_game *game, int i);

// Render
void		ft_redraw_gh(t_game *game);
void		ft_redraw_pacfood(t_game *game, t_player *pl);
void		ft_redraw_exit(t_game *game, t_player *pl);
void		ft_put_stopped(t_game *game, t_player *pl);
void		ft_redraw_pac(t_game *game);

// Chase
t_player	*ft_getnearestpac(t_game *game, t_player *ghost);
int			ft_choose_dir(t_game *game, t_player *gh, t_player *pac);
int			ft_findghost(t_player *pl, t_vector pos);
int			ft_advanced_dir(t_player *gh, t_player *pac, int *distances);
int			ft_advanced_dir2(int *distances);
// Legal
void		ft_update_legal(t_game *game, t_player *gh);
void		ft_restrict_legal(t_player *ghost);
int			ft_legal_len(t_player *player);
int			ft_in_legal(t_player *player, int dir);

#endif
