all: server1.c server2.c server3.c client.c main.h
	gcc server1.c -o server1.o
	gcc server2.c -o server2.o
	gcc server3.c -o server3.o
	gcc client.c -o client.o

clean:
	rm -f *.o