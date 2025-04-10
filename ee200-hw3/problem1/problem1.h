#include <stdio.h>
#include <stdbool.h>
#ifndef PROBLEM1_H
#define PROBLEM1_H

void compare(int all[], int multiples[], int len_all, int len_multiples, bool b);
int count_array(int all[], int len_all);
void clear_zeros(int all[], int primes[], int len_all, int num_primes);
void prime_seive(int a, int array1_n[]);
void factor_a(int factors[], int a);
void num_factors(int a, int num_prime_factors, int prime_factors[], int count[]);
int print_factors(int a);
#endif
