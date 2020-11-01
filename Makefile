all: build run

build:
	gcc -o cursedpong -l ncurses main.c

run:
	./cursedpong
