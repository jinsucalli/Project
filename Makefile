CC = g++
PROG = server
#OBJS = server.o
SOURCE = server_socket.cpp dbinterface.cpp 

$(PROG):$(SOURCE)
	$(CC) -std=c++11 -g -o $(PROG) $(SOURCE) -L/usr/local/sqlite/lib -lsqlite3

clean:
	rm server

do:$(PROG)
	./server
