SHELL = /bin/sh
#définition des commandes utilisees(
CC = gcc
RM = rm -rf
CP = rsync -R
#déclaration des options pour gcc
CFLAGS = -Wall
PROGNAME = Yahtzee
HEADERS = mecanismeJeu.h
SOURCES = main.c mecanismeJeu.c score.c
all:jeu

jeu:main.o score.o mecanismeJeu.o
	$(CC) $^ -o $(PROGNAME)
main.o: main.c
	$(CC) $(CFLAGS) -c $@

score.o: score.c score.h
	$(CC) $(CFLAGS) -c $@

mecanismeJeu.o: mecanismeJeu.c mecanismeJeu.h
	$(CC) $(CFLAGS) -c $@

clean: 
	$(RM) mecanismeJeu.o score.o main.o Yahtzee