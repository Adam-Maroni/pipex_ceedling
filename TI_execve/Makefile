#If "files are identical is given, then success"

LIBFT_ARCHIVE = ../libft/libft.a
SRC = $(wildcard ../src/*.c) test_excve.c
FLAGS = -g -fsanitize=address
CMD = "cat -ne"
FILE = "inFile"
OUTPUT1 = expected
OUTPUT2 = obtained
OUTEXE = test_excve

all:
	@gcc $(FLAGS) $(SRC) -D OUTPUT1=\"$(OUTPUT1)\" -D OUTPUT2=\"$(OUTPUT2)\" $(LIBFT_ARCHIVE) -o $(OUTEXE)
	@./$(OUTEXE) $(FILE) $(CMD)
	@echo "Command used : $(CMD) $(FILE)"
	@diff -s $(OUTPUT1) $(OUTPUT2) 

