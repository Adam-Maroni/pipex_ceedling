#If "files are identical is given, then success"

LIBFT_ARCHIVE = ../libft/libft.a
SRC = $(wildcard ../src/*.c) test_excve.c
FLAGS = -g -fsanitize=address
CMD = "cat"
FILE = "inFile"
OUTPUT1 = expected
OUTPUT2 = obtained
OUTEXE = test_excve
GDB_SCRIPT = ../gdbscripts/1.gdb
ARGV = $(FILE) $(CMD)

all:
	@gcc $(FLAGS) $(SRC) -D OUTPUT1=\"$(OUTPUT1)\" -D OUTPUT2=\"$(OUTPUT2)\" $(LIBFT_ARCHIVE) -o $(OUTEXE)
	@./$(OUTEXE) $(ARGV)
	@echo "Command used : $(CMD) $(FILE)"
	@diff -s $(OUTPUT1) $(OUTPUT2) 
gdb:
	@gcc $(FLAGS) $(SRC) -D OUTPUT1=\"$(OUTPUT1)\" -D OUTPUT2=\"$(OUTPUT2)\" $(LIBFT_ARCHIVE) -o $(OUTEXE)
	@gdb --x $(GDB_SCRIPT) -args ./$(OUTEXE) $(ARGV)

.DEFAULT: all
