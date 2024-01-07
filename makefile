CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror -std=c89 -g
OBJ = tictactoe.o fileReader.o UI.o game.o logs.o LinkedList.o
EXEC = TicTacToe

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
	
tictactoe.o : tictactoe.c fileReader.h UI.h
	$(CC) -c tictactoe.c $(CFLAGS)
	
fileReader.o : fileReader.c fileReader.h
	$(CC) -c fileReader.c $(CFLAGS)
	
UI.o : UI.c UI.h game.h logs.h
	$(CC) -c UI.c $(CFLAGS)
	
game.o : game.c game.h UI.h
	$(CC) -c game.c $(CFLAGS)
	
logs.o : logs.c logs.h
	$(CC) -c logs.c $(CFLAGS)
	
LinkedList.o : LinkedList.c logs.h
	$(CC) -c LinkedList.c $(CFLAGS)
	
clean :
	rm -f $(EXEC) $(OBJ)
	
run :
	valgrind --leak-check=full --track-origins=yes ./$(EXEC) settings.txt
	
debug :
	gdb ./$(EXEC)
	
ifdef Secret
CFLAGS += -D Secret
endif

ifdef Editor
CFLAGS += -D Editor
endif