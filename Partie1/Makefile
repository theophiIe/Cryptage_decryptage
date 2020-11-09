#Makefile tmp à refaire plus tard avec des .o
CC = g++
EXEC = main
CFLAGS = -std=c++17 -Wall -g

all : clean compile
	./$(EXEC)

compile :
	$(CC) $(CFLAGS) *.cc -o $(EXEC)

valgrind : compile
	valgrind --leak-check=full -v ./$(EXEC)

clean :
	rm -rf $(EXEC)
	ls
