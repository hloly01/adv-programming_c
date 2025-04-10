CFLAGS = -std=c99 -g
all: elements

elements: mon.c mon.h main.c
	gcc $(CFLAGS) mon.c main.c -o elements
clean:
	rm elements -f *.o tree.mon
valgrind: elements
	valgrind ./elements
comments: mon_comments.c main.c mon.h
	gcc $(CFLAGS) mon_comments.c main.c -o elements_commented
valgrind_full: elements
	valgrind --leak-check=full --track-origins=yes -s ./elements