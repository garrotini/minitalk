SERVER = server
CLIENT = client

CC = cc 
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): server.o
	$(CC) $(CFLAGS) server.c -o $(SERVER)

$(CLIENT): client.o
	$(CC) $(CFLAGS) client.c -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f server.o client.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
