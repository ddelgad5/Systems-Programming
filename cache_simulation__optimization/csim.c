#include "cachelab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void printHelp(); // to print out arguements and what they do
bool isNumber(char []); // test arguements

int main(int argc, char **argv)
{
  int indexBits, associativity, blockBits;
  int hits = 0;
  int misses = 0;
  int evictions = 0;
  bool verbose = false;
  FILE *fp; // for trace file
  char buff[255];
  // printf("Executing program\n");
  if (argc < 0) { // check if there are any arguements
    printf("ERROR\n");
    exit(-1);
  }
  else {
    for (int i=1; i < argc; i++) {
      // printf("Reading arguement\n");
      // printf("%s\n", argv[i]);
      if (strcmp(argv[i], "-v") == 0) { // Asking for verbose
        printf("verbose mode\n");
        verbose = true;
      }
      else if (strcmp(argv[i], "-h") == 0) { // Asking for help info
        if (verbose) printf("Asking for help\n");
        printHelp();
        exit(0);
      }
      else if (strcmp(argv[i], "-s") == 0) { // Asking for number of index bits
        // printf("Setting number of index bits\n");
        if (isNumber(argv[i+1])) {
          indexBits = atoi(argv[i+1]);
          printf("Index bits: %i\n", indexBits);
          i++;
        }
        else {
          printf("ERROR: No number is set\n");
          exit(-1);
        }
      }
      else if (strcmp(argv[i], "-E") == 0) { // Asking for associativity
        // printf("Setting associativity\n");
        if (isNumber(argv[i+1])) {
          associativity = atoi(argv[i+1]);
          printf("Associativity: %i\n", associativity);
          i++;
        }
        else {
          printf("ERROR: No number is set\n");
          exit(-1);
        }
      }
      else if (strcmp(argv[i], "-b") == 0) { // Asking for number of block bits
        // printf("Setting number of block bits\n");
        if (isNumber(argv[i+1])) {
          blockBits = atoi(argv[i+1]);
          printf("Block bits: %i\n", blockBits);
          i++;
        }
        else {
          printf("ERROR: No number is set\n");
          exit(-1);
        }
      }
      else if (strcmp(argv[i], "-t") == 0) { // Asking for tracefile
        printf("Asking for tracefile\n");
        // printf("%s\n", argv[i+1]);
        fp = fopen(argv[i+1], "r");
        while (fgets(buff, 255, (FILE *)fp)) {
          printf("%s\n", buff);
        }
        i++;
      }
      else {  //  catch invalid arguements
        // printf("ERROR: Invalid arguements\n");
        printHelp();
        exit(0);
      }
    }
  }
  printSummary(hits, misses, evictions);
  return 0;
}

void printHelp() {
  // printf("Inside printHelp()\n");
  printf("-h: Optional help flag that prints usage info\n");
  printf("-v: Optional verbose flag that displays trace info\n");
  printf("-s <s>: Number of set index bits (S = 2^s is the number of sets)\n");
  printf("-E <E>: Associativity (number of lines per set)\n");
  printf("-b <b>: Number of block bits (B = 2^b is the block size)\n");
  printf("-t <tracefile>: Name of the valgrind trace to replay\n");
  return;
}

bool isNumber(char number[]) {
  int n=0;
  if (number[0] == '-') { // check for negative
    n = 1; // start number on second element
    printf("ERROR: Number cannot be negative\n");
    exit(-1);
  }
  for (; number[n] != 0; n++) {
    if (!isdigit(number[n])) return false;
  }
  return true;
}
