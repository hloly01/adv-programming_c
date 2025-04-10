EE 200 Homework 15

# Overview
This assignment is the reverse of most that you've written so far: I have written some implementations of a binary search tree (for integers), and you will write the tests.  Your job is to figure out which of the 10 implementations actually does what is described in the header file `btree.h`.  Bonus points will be awarded if you come up with a test that breaks all of them (i.e., you find a real bug in my code).

You can use the provided Makefile to compile your code and run all your tests.

# Problem
For each of the 10 implementations, write a 1-sentence description of what the implementation is doing wrong, or how you determined that it is broken.  Only one of them works completely. (Unless there are bugs in my code, in which case none of them work completely!)

1. Assertion `new_values_sorted[i] == check_order[i]' failed. toArray() only identified top level
2.
3. Copy constructor does not create a deep copy. Double destruction causes seg fault
4. Copy constructor does not create a deep copy. Double destruction causes seg fault
5. Assertion `basics.contains(44) == 0' failed. Didn't remove value 
6. Seg faults if you remove a value that doesn't exist (should do nothing)
7. Does seem to remove value (based on printed array) but still fails assertion `basics.contains(44) == 0'. Something isn't updated correctly.
8. Assertion `hundred.contains(val_100[i])' failed. Doesn't handle large arrays(>1000 is bad)
9.
10. Can't create a copy of an empty array. (seg fault)

# Submission
You don't need to submit anything on Gradescope, just push your test code and your updated README to Github.

