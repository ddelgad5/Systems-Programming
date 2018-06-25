#include "cachelab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printHelp();

int main(int argc, char **argv)
{
  int indexBits, associativity, blockBits;
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
        printf("verbose mode");
      }
      else if (strcmp(argv[i], "-h") == 0) { // Asking for help info
        printf("Asking for help\n");
        printHelp();
        exit(0);
      }
      else if (strcmp(argv[i], "-s") == 0) { // Asking for number of index bits
        printf("Setting number of index bits\n");
        indexBits = *argv[i+1];
        printf("Index bits: %i\n", indexBits);
        i++;
      }
      else if (strcmp(argv[i], "-E") == 0) { // Asking for associativity
        printf("Setting associativity\n");
        associativity = *argv[i+1];
        printf("Associativity: %i\n", associativity);
        i++;
      }
      else if (strcmp(argv[i], "-b") == 0) { // Asking for number of block bits
        printf("Setting number of block bits\n");
        blockBits = *argv[i+1];
        printf("Block bits: %i\n", blockBits);
        i++;
      }
      else if (strcmp(argv[i], "-t") == 0) { // Asking for tracefile
        printf("Asking for tracefile\n");
      }
      else {  //  catch invalid arguements
        // printf("ERROR: Invalid arguements\n");
        printHelp();
        exit(0);
      }
    }
  }
  printSummary(0, 0, 0);
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
