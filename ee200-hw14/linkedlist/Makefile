linkedlist:linkedlist.h test_linkedlist.cpp
	g++ test_linkedlist.cpp -o linkedlist
valgrind: linkedlist
	valgrind --leak-check=full --track-origins=yes -s ./linkedlist