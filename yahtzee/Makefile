#définition des commandes utilisees(
CC = gcc
RM = rm -rf
#déclaration des options pour gcc
CFLAGS = -Wall
PROGNAME = Yahtzee

all: main score mecanismeJeu
	$(CC) $(CFLAGS) -o $(PROGNAME) main.o score.o mecanismeJeu.o 

main: main.c
	$(CC) $(CFLAGS) -c $@.c

score: score.c score.h
	$(CC) $(CFLAGS) -c $@.c

mecanismeJeu: mecanismeJeu.c mecanismeJeu.h
	$(CC) $(CFLAGS) -c $@.c

clean: 
	$(RM) mecanismeJeu.o score.o main.o $(PROGNAME)