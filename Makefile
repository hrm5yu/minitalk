SERVER = server
CLIENT = client
LIBFT = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L./libft -lft
SRCS = server_main.c client_main.c
OBJS = $(SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft

$(SERVER): $(LIBFT) server_main.o
	$(CC) server_main.o $(LIBS) -o $(SERVER)

$(CLIENT): $(LIBFT) client_main.o
	$(CC) client_main.o $(LIBS) -o $(CLIENT)

clean:
	rm -rf *.o ./libft/*.o

fclean:	clean
	rm -rf $(CLIENT) $(SERVER) ./libft/libft.a

re: fclean all