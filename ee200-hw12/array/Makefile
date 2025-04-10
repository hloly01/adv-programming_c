array:array.h test_array.cpp
	g++ test_array.cpp -o array

valgrind: array
	valgrind --leak-check=full --track-origins=yes -s ./array
