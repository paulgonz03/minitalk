CLIENT = client
SERVER = server
CFLAGS = -Wall -Wextra -Werror 

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	gcc $(CFLAGS) server.c $ -o $(SERVER)

$(CLIENT):
	gcc $(CFLAGS) client.c $ -o $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT) 

fclean: clean

re: fclean all 

.PHONY: all flean clean re