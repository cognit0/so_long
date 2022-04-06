NAME=so_long

LIBFT=lib/libft/libft.a
LIBMLX=lib/minilibx_macos/libmlx.a
INCLUDES=inc
FRAMEWORKS=-framework OpenGL -framework AppKit
SRC=src/main.c src/init.c src/draw.c src/utils.c src/render.c src/input.c src/map.c src/map2.c src/read_map.c \
src/moves.c src/game.c
OBJ=main.o init.o draw.o utils.o render.o input.o map.o map2.o read_map.o moves.o game.o

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $? $(FRAMEWORKS) $(LIBMLX) $(LIBFT) -lm
	@rm -rf *.o

$(OBJ): $(SRC)
	@make -C lib/minilibx_macos
	@make -C lib/libft
	@gcc -c $? -I $(INCLUDES)

exe: all
	@make
	@rm -rf *.o
	@./$(NAME)

clean:
	@rm -rf *.o

fclean:
	@make clean
	@rm -rf $(NAME)
	@make clean -C lib/minilibx_macos
	@make fclean -C lib/libft

re:
	@make fclean
	@make -C ./

val	:	${NAME}
	valgrind \
	--leak-check=full --tool=memcheck \
	--show-reachable=yes \
	--track-fds=yes \
	--errors-for-leak-kinds=all \
	--show-leak-kinds=all ./${NAME}

.PHONY: all re clean fclean
