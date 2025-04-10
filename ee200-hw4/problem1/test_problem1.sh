#! /bin/bash

# This is a shell script which you can use to test your code
# To provide input, you can pipe text to standard input, which will be read by scanf

# `echo` just prints out whatever its command-line arguments are, and
# the `|` pipes the output of one command to the input of another.

result=`echo "2 + 13" | ./problem1`
if [ "$result" != "15.000000" ]; then echo "Test failed, expected \"3.000000\" but got \"$result\"."; fi
if [ "$result" == "15.000000" ]; then echo "Test passed"; fi
result=`echo "5 - 7" | ./problem1`
if [ "$result" != "-2.000000" ]; then echo "Test failed, expected \"3.000000\" but got \"$result\"."; fi
if [ "$result" == "-2.000000" ]; then echo "Test passed"; fi
result=`echo "2" | ./problem1`
if [ "$result" != "error: this equation is invalid" ]; then echo "Test failed, expected \"3.000000\" but got \"$result\"."; fi
if [ "$result" == "error: this equation is invalid" ]; then echo "Test passed"; fi
result=`echo "1 ^ 0" | ./problem1`
if [ "$result" != "1.000000" ]; then echo "Test failed, expected \"3.000000\" but got \"$result\"."; fi
if [ "$result" == "1.000000" ]; then echo "Test passed"; fi
result=`echo "0 ^ 0" | ./problem1`
if [ "$result" != "1.000000" ]; then echo "Test failed, expected \"3.000000\" but got \"$result\"."; fi
if [ "$result" == "1.000000" ]; then echo "Test passed"; fi
result=`echo "1 / 0" | ./problem1`
if [ "$result" != "error: cannot divide by zero." ]; then echo "Test failed, expected \"3.000000\" but got \"$result\"."; fi
if [ "$result" == "error: cannot divide by zero" ]; then echo "Test passed"; fi
result=`echo "0 / 0" | ./problem1`
if [ "$result" != "error: cannot divide by zero." ]; then echo "Test failed, expected \"3.000000\" but got \"$result\"."; fi
if [ "$result" == "error: cannot divide by zero" ]; then echo "Test passed"; fi
result=`echo "5 * 0" | ./problem1`
if [ "$result" != "0.000000" ]; then echo "Test failed, expected \"3.000000\" but got \"$result\"."; fi
if [ "$result" == "0.000000" ]; then echo "Test passed"; fi
result=`echo "2.25 ^ 4" | ./problem1`
result=`echo "10 / 3" | ./problem1`

# You can check the results with the following scripting magic:
result=`echo "1 + 2" | ./problem1`
if [ "$result" != "3.000000" ]; then echo "Test failed, expected \"3.000000\" but got \"$result\"."; fi
if [ "$result" == "3.000000" ]; then echo "Test passed"; fi