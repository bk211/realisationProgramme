#définition des commandes utilisees(
CC = gcc
RM = rm -rf
#déclaration des options pour gcc
CFLAGS = -Wall
PROGNAME = Yahtzee

all: main.o score.o mecanismeJeu.o
	$(CC) $(CFLAGS) -o $(PROGNAME) main.o score.o mecanismeJeu.o 

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

score.o: score.c score.h
	$(CC) $(CFLAGS) -c score.c

mecanismeJeu.o: mecanismeJeu.c mecanismeJeu.h
	$(CC) $(CFLAGS) -c mecanismeJeu.c

clean: 
	$(RM) mecanismeJeu.o score.o main.o $(PROGNAME)