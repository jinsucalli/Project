CC = g++
PROG = client
SOURCE = client.cpp client_socket.cpp

$(PROG):$(SOURCE)
		  $(CC) -std=c++11 -g -o $(PROG) $(SOURCE)

clean:
	rm client
