CC = gcc
RM = rm -rf
#déclaration des options pour gcc
CFLAGS = -Wall -g
PROGNAME = Navalfight

all: main.o create_grid.o boucle.o afficha.o defaite.o test_couler.o put_couler.o color.o
	$(CC) $(CFLAGS) -o $(PROGNAME) main.o create_grid.o boucle.o afficha.o defaite.o test_couler.o put_couler.o color.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

create_grid.o :create_grid.c
	$(CC) $(CFLAGS) -c create_grid.c

boucle.o: boucle.c
	$(CC) $(CFLAGS) -c boucle.c
afficha.o: afficha.c
	$(CC) $(CFLAGS) -c afficha.c

defaite.o: defaite.c
	$(CC) $(CFLAGS) -c defaite.c

test_couler.o: test_couler.c
	$(CC) $(CFLAGS) -c test_couler.c
put_couler.o: put_couler.c
	$(CC) $(CFLAGS) -c put_couler.c

color.o: color.c
	$(CC) $(CFLAGS) -c color.c









clean: 
	$(RM) *.o $(PROGNAME)
