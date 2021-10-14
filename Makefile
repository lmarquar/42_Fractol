CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra
SRC		:= fractol.c fractol_functions.c ft_atod_bonus.c putcolor.c
NAME	:= fractol.exe
M_LIBS	:= -L /usr/X11/lib -lXext -lX11
M_LBMLX	:= libmlx.a
L_NAME	:= fractoll.exe
L_LIBS	:= -lXext -lX11 -lm
L_LBMLX	:= libmlx_Linux.a

all: $(NAME)

re: clean $(NAME)

linux: $(L_NAME)

linux_re: clean $(L_NAME)

$(NAME):
	$(CC) $(CFLAGS) $(M_LIBS) $(SRC) $(M_LBMLX) -o $(NAME)

$(L_NAME):
	$(CC) $(CFLAGS) $(SRC) $(L_LBMLX) $(L_LIBS) -o $(L_NAME)

clean:
	rm -f $(NAME)
	rm -f $(L_NAME)

fclean: clean
