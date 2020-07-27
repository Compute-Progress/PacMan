NAME = PacMan
FLAGS = -Wall -Wextra -Werror

INCL = -I incl/
SLIB = -L ~/.brew/lib  -l SDL2 -l sdl2_image

FILES = main init render level_funcs ghosts parse updates

SRCS = $(addprefix srcs/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix objects/, $(addsuffix .o, $(FILES)))

############################################################

all: $(NAME)

objects/%.o: srcs/%.c
	@/bin/mkdir -p objects
	gcc $(FLAGS) -c $(INCL) $< -o $@

$(NAME): $(OBJS)
	gcc $(FLAGS) $(INCL) $(SLIB) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: $(NAME) clean fclean push re
