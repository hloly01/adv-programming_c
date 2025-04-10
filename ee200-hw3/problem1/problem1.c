#include <stdlib.h>
#include "problem1.h"
#define keep_duplicates 1
#define discard_duplicates 0

/*
THE PLAN

User inputs integer number (n)
1) Generate a list (list_1) ranging from 1 to n
2) Use a prime sieve to identify the primes 
  a) Generate a secondary list that has all multiples of 2
  b) Set any overlapping values between the lists to zero in list_1 (compare function)
  c) For the next non-zero value in list_1, generate a list of its multiples
  d) repeat for i < n
  e) count the number of primes ie non-zero values in list_1 (count_array function)
  f) create a new list and populate it with the primes (clear zeros function)
3) Identify the factors of n
4) Compare with prime list 
5) repeat b, e, and f?
6) Identify how many times each prime should be repeated

*/

// compare two arrays, set matching values to zero if b, otherwise set matches to zero
void compare(int all[], int multiples[], int len_all, int len_multiples, bool b) { 
  bool match = 0;
  for (int i = 0; i < len_all; i++) {     
    match = 0;
    if (*(all+i) != 0){
      for (int j = 0; j < len_multiples; j++){ 
        if (*(multiples + j) == *(all+i)) { 
          match = 1;
          if (!b){ // discard duplicates
            *(all+i) = 0;
          }
          break;
        } 
        }
      if (b) { // If we're keeping duplicates, then set to zero
        if (!match) { 
          *(all+i) = 0;
        }
      }
    }
  }
}
int count_array(int all[], int len_all) { // count number of non-zero values in an array
  int i;
  int num_primes = 0; 
  for (i = 0; i < len_all; i++)
    if (*(all+i) !=0) {
      num_primes++;
    }
  return num_primes;
}
// populate primes[] with all nonzero values in all[]
void clear_zeros(int all[], int primes[], int len_all, int num_primes) { 
  int i;
  int cell = 0;
  for (i = 0; i < len_all; i++)
    if (*(all+i) !=0) {
      *(primes + cell) = *(all+i);
      cell++;
    }
}

// prime sieve to find all primes < a
void prime_seive(int a, int array1_n[]){
  int i; int j;
    for (i = 2; i < (a - 1); i++) {
    if (*(array1_n + i - 2) != 0) {
      int len_temp = (a/i) - 1; // a stays because referencing value not length
      int temp[len_temp];
      for (j = 0; j < len_temp; j++) {
        temp[j] = i*(j+2); 
      }
      compare(array1_n, temp, (a - 1), len_temp, discard_duplicates);
    }
  }
}

void factor_a(int factors[], int a){ // finds all factors of a
  int i;
  for (i = 2; i <= a; i++) {
    if (a % i == 0) { // if a is divisible by i with no remainder, i is a factor 
      *(factors + i - 2) = i;
    } else {*(factors + i - 2) = 0;}
  }
}
// determine how many times a is divisible by each prime factor
void num_factors(int a, int num_prime_factors, int prime_factors[], int count[]){
  int i;
  for (i = 0; i < num_prime_factors; i++){
    *(count + i) = 0;
    int test;
    for (test = *(prime_factors + i); a % test == 0; test = test* *(prime_factors + i)) {
      *(count + i) = *(count + i) + 1;
      } 
    }
}

int print_factors (int a) { // how to create an array w/ for loop https://stackoverflow.com/questions/45591891/create-an-array-of-consecutive-numbers-from-1-to-n-in-c
  int i;
  int j;
  if (a <= 1){return -1;}
  // Step 1 is working
  int array_all[a - 1];
  for(i = 0; i < (a-1); i++) { // array_all has length a - 1 
    array_all[i] = i + 2;
  }

  // Step 2: Identify all primes < a. Step 2 is working
  prime_seive(a, array_all); 
  int num_primes = count_array(array_all, (a-1));
  int primes[num_primes]; 
  clear_zeros(array_all, primes, (a - 1), (num_primes));

  // Step 3: Identify all factors for a. Step 3 is working
  int factors[a-1];
  factor_a(factors, a); 

 // Step 4 & 5 & 6: Call functions to compare primes and factors

 // get rid of all factors that aren't prime
  compare(factors, primes, (a-1), num_primes, keep_duplicates); // length of factors is a-1
  int num_prime_factors = count_array(factors, (a-1)); 
  int prime_factors[num_prime_factors]; 
  clear_zeros(factors, prime_factors, (a), num_prime_factors); // populate prime_factors 
  int count[num_prime_factors];
  // determine how many times a factor should be printed
  num_factors(a, num_prime_factors, prime_factors, count); 

  for(i = 0; i < (num_prime_factors); i++) {
    for (j = 0; j < count[i]; j++){
      printf("%d ", *(prime_factors + i));
    }
  }
  printf("\n");

return 0;
}
