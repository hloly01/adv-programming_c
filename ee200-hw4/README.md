# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

Geeksforgeeks: 
- https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/ (CLI args)
- https://www.geeksforgeeks.org/time-function-in-c/ (time())
- https://www.geeksforgeeks.org/gmtime-function-in-c-c/ (gmtime())
- https://www.geeksforgeeks.org/convert-a-char-array-to-double-in-c/ (type conversion stuff)

Stack Overflow: 
- https://stackoverflow.com/questions/6310008/what-language-uses-fi (curious about shell script fi)
- https://stackoverflow.com/questions/35860794/how-to-print-argv-arguments-from-main-function-in-c (CLI input)
- https://stackoverflow.com/questions/153890/printing-leading-0s-in-c (leading zero's)

Other: 
- https://www.calculator.net/time-duration-calculator.html (time caclulator)
- https://kb.iu.edu/d/aqsj#scanf (to fix seg fault)

Zach advised me to change abs() to fabs() to achieve float accuracy in my Problem 1 calculator. 

# Overview
This classwork set is very similar to the previous one; you'll be writing functions which perform particular operations.

For the first problem, you'll write the entire program (we've provided a skeleton main() function, but that's all).

# Submission
You should commit and push your code to GitHub when you reach any significant milestone (you finish a problem, or get a function tested and working).
When you are finished, submit your code on Gradescope via Github.

# Problems
## 1.
scanf() is sort of the reverse of printf(): it reads input and converts values according to a format string.  For example, to read two integers:

    scanf("%d %d", number1, number2);

The catch is that since scanf needs to modify the arguments, they must be pass-by-reference.  That is, number1 and number2 are not ints, but rather pointers to ints.

Write a command-line calculator program that reads what to do using scanf.  Your code should take both operands and the operation all on one line (e.g., "4.5 + 3") and then print the result.  You should re-use your calculator code from the previous assignment, and just add scanf to get the arguments.

As before, if something invalid is entered, your code should print a message containing the word "error".

Make sure that you're making use of full double-precision numbers.  Both scanf and printf have options to control the precision and may not do what you want by default.  A double-precision number should be accurate to about 15 significant figures.

To test your code, you should use the script `test_problem1.sh`.  Don't just run tests manually from the command line; this makes it impossible for others to see what things you tested.  Using the shell script also makes it very easy to run all of your tests every time you make a change, in case you broke something that worked before.

## 2.
Write a function that prints the date and time represented by a `time_t`, using the exact format: `Weekday, Month Day, Year hours:minutes:seconds`.  Hours should be in 24-hour format (i.e., no AM/PM).  Pay careful attention to the spacing and punctuation.
For example, `Wednesday, September 04, 2019 16:30:02`

The result should be in UTC (aka GMT), not US Eastern daylight time (which is UTC -4 hours).
You will probably want to use the time() and gmtime() functions.  You can access the help pages with `man 2 time` and `man gmtime`.
Read the man pages carefully; the numerical values returned in the struct may not match your expectations.

There is a function (`strftime`) which performs the bulk this task.  Since the point of this problem is to practice using pointers and structs, you should not use this function in your implementation.

## 3.
We use pass-by-reference when the function needs to modify the parameters, but it can also be useful when the parameters take a large amount of memory and we want to avoid the overhead of copying them.

To simulate this case, write a new version of your which-triangle-is-larger function which operates with pass-by-reference.  If one triangle is NULL, then you should return the non-NULL one as "larger".

