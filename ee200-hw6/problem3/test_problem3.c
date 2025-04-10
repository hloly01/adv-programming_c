#include "problem3.h"

int main(int argc, char* argv[])
{
  int i;
  char test_1[38] = ": hello, ABCDEFGHIJKLMNOPQRSTUVWXYZ! ";
  unsigned int hist[26];
  find_frequency(test_1, 38, hist);
  for (i = 0; i < 26; i++) {
    printf("%c: %d\t", (97 + i), hist[i]);
  }
  printf("\n\n");

  char test_2[45] = "The quick brown fox jumps over the lazy dog.";
  find_frequency(test_2, 45, hist);
  for (i = 0; i < 26; i++) {
    printf("%c: %d\t", (97 + i), hist[i]);
  }

  find_frequency(NULL, 0, hist);

  printf("\nall done!\n");
  return(0);
}

