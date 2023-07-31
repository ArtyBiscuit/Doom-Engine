_END="\033[0m"
_RED="\033[0;31m"
_GREEN="\033[0;32m"
_YELLOW="\033[0;33m"
_CYAN="\033[0;36m"

SRC_DIR = src
OBJ_DIR = obj
LIBX_DIR = lib/minilibx
CC = clang
CFLAGS = -Wall -Werror -Wextra -g3
INC = -Iinclude -Iinc
LIB = -ldl -lglfw -pthread -lm -L$(LIBX_DIR) -lmlx42
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
MAKE_LIBX = $(LIBX_DIR)/libmlx42.a

################## SRC ###################
SRC	= src/main.c		\
	  src/disp_grid.c	\
	  src/trace_line.c	\
	  src/draw_sector.c	\
	  src/new_point.c	\
	  src/new_wall.c	\
	  src/draw_point.c	\
	  src/mouse_hook.c	\
	  src/mouv_point.c
##########################################

NAME = DOOM_PROJECT

all: $(NAME)

$(NAME): $(MAKE_LIBX) $(OBJ_DIR) $(OBJ)
	@echo $(_GREEN)Compiling $(OBJ)...$(END)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)
$(MAKE_LIBX):
	$(MAKE) -C $(LIBX_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo $(_CYAN)Compiling $<...$(END)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC)

clean:
	@echo $(_YELLOW)Cleaning $(OBJ)...$(END)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(_RED)Cleaning $(NAME)...$(END)
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
