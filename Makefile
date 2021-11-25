NAME = pipex
SRC = tmpSrc.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = clang

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	./$(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

mem_check: $(OBJ)
	$(CC) $(CFLAGS) -fsanitize=address -g $(OBJ) -o $(NAME)

valgrind: $(OBJ)
	$(CC) $(CFLAGS) -g $(OBJ) -o $(NAME)
