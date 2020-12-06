all: run link

run: link
	./main

link:
	gcc main.c -o main
