all:
	make -s clean
	make -s path
	make -s build

build: server1.c server2.c server3.c bonus_server.c client.c scale_client.c bonus_client.c main.h
	gcc server1.c -o bin/server1.o
	gcc server2.c -o bin/server2.o
	gcc server3.c -o bin/server3.o
	gcc client.c -o bin/client.o
	gcc bonus_server.c -o bin/bonus_server.o
	gcc bonus_client.c -o bin/bonus_client.o
	gcc scale_client.c -o bin/scale_client.o

path:
	mkdir bin

clean:
	rm -rf bin/