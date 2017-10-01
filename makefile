CC		= g++
CFLAGS	= -g3 -Wall
EXEC 	= musicchairs
OBJS 	= chain.o list.o main.o
SRCS 	= chain.cpp list.cpp main.cpp


.PHONY : all

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

list.o: list.cpp
	$(CC) $(CFLAGS) -c list.cpp

chain.o: chain.cpp
	$(CC) $(CFLAGS) -c chain.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp


.PHONY: clean

clean:
	rm -f $(OBJS) $(EXEC)



.PHONY: run

run:
	./$(EXEC)
