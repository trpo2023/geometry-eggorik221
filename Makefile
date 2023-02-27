all: app

app: geom.c
	gcc -Wall -o app geom.c

