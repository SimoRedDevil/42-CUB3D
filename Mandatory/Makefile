# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 21:30:31 by mel-yous          #+#    #+#              #
#    Updated: 2023/09/29 12:10:17 by mel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc -Ofast -O3 -I ../mlx/ -I ../libft/ -I ../get_next_line/
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HDR = cub3d.h ../libft/libft.h ../get_next_line/get_next_line.h
GNL = ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
LIB = ../libft/
LIBFT =	$(LIB)ft_putchar_fd.c $(LIB)ft_strjoin.c $(LIB)ft_strlcat.c\
		$(LIB)ft_atoi.c $(LIB)ft_putendl_fd.c $(LIB)ft_substr.c\
		$(LIB)ft_bzero.c $(LIB)ft_strlcpy.c $(LIB)ft_putstr_fd.c\
		$(LIB)ft_strlen.c $(LIB)ft_split.c $(LIB)ft_isalpha.c\
		$(LIB)ft_memcpy.c $(LIB)ft_strchr.c $(LIB)ft_strchr1.c\
		$(LIB)ft_strdup.c $(LIB)ft_isdigit.c $(LIB)ft_memset.c
OBJ_DIR = obj
SRC = main.c \
g_collector.c \
cub3d_utils.c \
parsing/map_reader.c \
initializer/init_data.c \
initializer/init_mlx.c \
initializer/init_player.c \
parsing/color_parser.c \
parsing/texture_parser.c \
parsing/map_parser.c \
parsing/parsing_utils.c \
my_mlx_func.c \
raycasting/raycasting.c \
raycasting/raycasting_utils.c \
info_getter.c \
drawing/draw_walls.c \
drawing/drawing_utils.c \
engine/move_player.c \
engine/move_left_right.c \
engine/move_up_down.c \
engine/move_player_utils.c \
engine/rotation.c \
$(GNL) $(LIBFT)

# yellow = "\033[33m"
# Generate the list of object files with the same structure as SRC but in OBJ_DIR
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

MLX = ../mlx/libmlx.a
MLXFLAGS = -framework OpenGL -framework AppKit
all: $(NAME) show_banner

BANNER_TEXT = "\
	░█████╗░██╗░░░██╗██████╗░██████╗░██████╗░\
	██╔══██╗██║░░░██║██╔══██╗╚════██╗██╔══██╗\
	██║░░╚═╝██║░░░██║██████╦╝░█████╔╝██║░░██║\
	██║░░██╗██║░░░██║██╔══██╗░╚═══██╗██║░░██║\
	╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝\
	░╚════╝░░╚═════╝░╚═════╝░╚═════╝░╚═════╝░"

show_banner:
	@printf "\033[32m%s\033[0m\n" "$(BANNER_TEXT)"
	@printf "\t\tCopyright (c) 2023 \033[1;35m%s\033[0m\n" "aben-nei, mel-yous"

# Rules for creating the executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX) $(OBJ) $(MLXFLAGS) -o $(NAME)
	@clear
	@echo ""$@ "\033[1;32mhas ben Created\033[0m ...\033[0m"


# Rules for creating object files in the OBJ_DIR
$(OBJ_DIR)/%.o: %.c $(HDR)
	@mkdir -p $(@D)  # Create the directory if it doesn't exist
	@$(CC) $(CFLAGS) -c $< -o $@
	@clear
	@$(eval CNT := $(shell echo $$(($(CNT)+1))))
	@$(eval PERCENT := $(shell echo $$(($(CNT) * 100 / $(words $(SRC))))))
	@printf "\033[32mCompiling: \033[0m%-50s \033[32m%d%%\033[0m\n" "$(notdir $<)" "$(PERCENT)"

bonus:
	make -C ../bonus
fclean_bns:
	make fclean -C ../bonus
# Rules for cleaning generated .o files
fclean: clean
	@$(RM) $(NAME)
	@clear
	@echo "\033[1;31mDeleting\033[0m" $(NAME) "\033[1;31m...\033[0m"

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r libft
	@$(RM) -r get_next_line
	@clear
	@echo "\033[1;31mDeleting\033[0m" Object files "\033[1;31m...\033[0m"

re: fclean all
