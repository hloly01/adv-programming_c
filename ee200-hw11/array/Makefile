array:array.h test_array.cpp array.cpp
	g++ array.cpp test_array.cpp -o array

valgrind: array
	valgrind --leak-check=full --track-origins=yes -s ./array