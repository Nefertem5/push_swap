NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I.

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	
re: fclean all
