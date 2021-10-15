# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:11:24 by lignigno          #+#    #+#              #
#    Updated: 2021/10/15 08:58:01 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re check_obj_dir

# _____________________________________________________________________VARIABLES

COL_0					:=	\033[38;2;0;145;15
COL_1					:=	\033[38;2;46;84;240
COL_2					:=	\033[37
UNSET					:=	\033[m

NAME					:=	so_long

CC						:=	gcc
OBJ_DIR					:=	obj
FLAGS					:=	-Wall -Wextra -Werror
INCLUDE					:=	srcs/headers
MLX_DIR					:=	srcs/mlx
LIBS					:=	$(MLX_DIR)/libmlx.a
VPATH					:=	srcs \
							srcs/inits \
							srcs/event_handling_functions \
							srcs/utils \
							srcs/rendering \
							srcs/animation \
							srcs/parser \
							srcs/gnl \
							srcs/animation


SRC						:=	main.c \
							init.c \
							init_pers.c \
							init_objects.c \
							key_press.c \
							key_release.c \
							end_game.c \
							cut_piece.c \
							set_pixel_color.c \
							get_pixel_color.c \
							rendering.c \
							move_management.c \
							check_error.c \
							parser.c \
							load_map.c \
							ft_strlen.c \
							find_road.c \
							img_on_img.c \
							get_time.c \
							check_map.c \
							pave_the_road.c \
							set_objs_on_map.c \
							draw_map.c \
							set_xy_of_map.c \
							check_collision.c \
							new_gnl.c \
							new_gnl_utils.c


OBJ						:=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
DEP						:=	$(wildcard $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.d))))

# _______________________________________________________________________TARGETS

all						:	other_libs_rule $(OBJ_DIR) $(NAME)

$(NAME)					:	$(OBJ)
							@$(CC) $(OBJ) $(LIBS) -framework OpenGL -framework AppKit -o $@
							@echo "$(COL_0);1m"
							@echo "\t\tCOMMAND + V"
							@echo "$(UNSET)"
							@printf "$(shell pwd)/$@ map.ber" | pbcopy

$(OBJ_DIR)/%.o			:	%.c
							$(CC) $(FLAGS) -I $(INCLUDE) -MD -c $< -o $@

$(OBJ_DIR)				:
							@mkdir -p $(OBJ_DIR)/

other_libs_rule: $(MLX_DIR)
							@make -C $<

include $(DEP)
# ________________________________________________________________CLEANS TARGETS

clean					:
							@make clean -C $(MLX_DIR)
							@rm -rf $(OBJ_DIR)
							@echo "$(COL_1);3;1mobject\033[23;22m files for \033[3;1m$(NAME)\033[23;22m have been deleted\033[0m"

fclean					:	clean
							@rm -f $(NAME)
							@echo "$(COL_1);3;1m$(NAME)\033[23;22m have been deleted\033[0m"

re						:	fclean all
