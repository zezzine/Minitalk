NAME = server
NAME_CLIENT = client

S_SRV = server_side.c tools.c
S_CLIENT = client_side.c tools.c

OBJ_SRV = server_side.o tools.o
OBJ_CLIENT = client_side.o tools.o

CFLAGS = -Wall -Werror -Wextra -c

all : $(NAME)

$(NAME): $(S_CLIENT) $(S_SRV)
		@gcc $(CFLAGS) $(S_SRV)
		@gcc $(OBJ_SRV) -o $(NAME)
		@echo "make server"
		@gcc $(CFLAGS) $(S_CLIENT)
		@gcc $(OBJ_CLIENT) -o $(NAME_CLIENT)
		@echo "make client"

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SRV)

fclean:	clean
	rm -f $(OBJ_CLIENT) $(OBJ_SRV) $(NAME) $(NAME_CLIENT)

re: fclean all

.PHONY: all re fclean clean