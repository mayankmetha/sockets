socket: main.o server.o client.o
	gcc -o socket main.o server.o client.o

main.o: main.c main.h
	gcc -c main.c

server.o: server.c main.h
	gcc -c server.c

client.o: client.c main.h
	gcc -c client.c

clean:
	rm -f *.o socket