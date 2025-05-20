NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): server.c
	$(CC) $(CFLAGS) -o $(NAME_SERVER) server.c

$(NAME_CLIENT): client.c
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) client.c

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: clean all
