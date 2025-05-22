NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRINTF = Printf/libftprintf.a

all: $(NAME_SERVER) $(NAME_CLIENT)

$(PRINTF):
	$(MAKE) -C ./Printf

$(NAME_SERVER): server.c $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_SERVER) server.c -L./Printf -lftprintf

$(NAME_CLIENT): client.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_CLIENT) client.c

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C ./Printf fclean

re: fclean all

.PHONY: all clean fclean re
