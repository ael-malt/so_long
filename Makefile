# COMPILATION
NAME		= so_long
CC			= clang
FLAGS		= -Wall -Wextra -Werror -g

# LIBFT
LIBFT_PATH	= ./libft/
LIBFT_FILE	= libft.a
LIBFT_LIB	= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

# MLX
MLX_PATH	= ./minilibx-linux/
MLX_FILE	= libmlx.a
MLX_LIB		= $(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_FLAG	= -lX11 -lXext
MLX_EX		= $(MLX_LIB) $(MLX_FLAG)

# FILES
C_FILE		=  anim.c \
				anim_dir.c \
				chase.c \
				check.c \
				game.c \
				ghosts.c \
				legal.c \
				load_dir.c \
				main.c \
				map.c \
				pacman.c \
				player.c \
				playerlist.c \
				render.c \
				score.c \
				sprites.c \
				utils.c \

# DIRECTORIES
SRC_DIR		=	./src/
INC_DIR		=	./includes/
SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))
OBJ			=	$(SRC:.c=.o)

.c.o:
			$(CC) $(FLAG) -c $< -o $@

all:		$(NAME)

lib:
			@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
			@make -C $(LIBFT_PATH)
			@echo "\033[1;32mLIBFT_lib created\n"

mlx:
			@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
			@make -sC $(MLX_PATH)
			@echo "\033[1;32mMLX_lib created\n"

$(NAME):	lib mlx $(OBJ)
			@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
			$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
			@echo "\033[1;32m./so_long created\033[0;39m\n"

clean:
			@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
			@make clean -sC $(MLX_PATH)
			@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
			@make clean -sC $(LIBFT_PATH)
			@echo "\033[1;32mDone\n"
			@echo "\033[0;31mDeleting So_long object...\n"
			@rm -f $(OBJ)
			@echo "\033[1;32mDone\n"

fclean:		clean
			@echo "\033[0;31mDeleting so_long executable..."
			@rm -f $(NAME)
			@make fclean -C $(LIBFT_PATH)
			@echo "\033[1;32mDone\n"

re:			fclean all

.PHONY:		all clean fclean re
