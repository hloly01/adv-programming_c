priorityqueue:priorityqueue.h test_priorityqueue.cpp
	g++ test_priorityqueue.cpp -o priorityqueue -pthread

valgrind: priorityqueue
	valgrind --leak-check=full --track-origins=yes -s ./priorityqueue