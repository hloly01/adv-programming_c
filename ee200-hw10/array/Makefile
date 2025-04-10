array:array.h test_array.cpp
	g++ test_array.cpp -o array

new: array.h test_array_newfail.cpp
	g++ test_array_newfail.cpp -o new

valgrind: array
	valgrind --leak-check=full --track-origins=yes -s ./array