NAME = pac_man
FILES = init main updates level_funcs

all : $(NAME)

$(NAME) :
	gcc -I incl/ -L ~/.brew/lib -l SDL2 -l sdl2_image srcs/*.c
