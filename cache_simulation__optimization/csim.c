#include "cachelab.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  int indexBits, associativity, blockBits;
  printf("Executing program\n");
  if (argc < 0) { // check if there are any arguements
    printf("ERROR\n");
    return(-1);
  }
  else {
    for (int i=1; i < argc; i++) {
      printf("Reading arguement\n");
      printf(argv[i] ,"\n");
      if (strcmp(argv[i], "-v") == 0) { // Asking for verbose
        printf("verbose mode");
      }
      else if (strcmp(argv[i], "-h") == 0) { // Asking for help info
        printf("Asking for help\n");
      }
      else if (strcmp(argv[i], "-s") == 0) { // Asking for number of index bits
        printf("Setting number of index bits\n");
        indexBits = *argv[i+1];
        printf("%i\n", indexBits);
        i++;
      }
      else if (strcmp(argv[i], "-E") == 0) { // Asking for associativity
        printf("Setting associativity\n");
        associativity = *argv[i+1];
        printf("%i\n", associativity);
        i++;
      }
      else if (strcmp(argv[i], "-b") == 0) { // Asking for number of block bits
        printf("Setting number of block bits\n");
        blockBits = *argv[i+1];
        printf("%i\n", blockBits);
        i++;
      }
      else if (strcmp(argv[i], "-t") == 0) { // Asking for tracefile
        printf("Asking for tracefile\n");
      }
      else {  //  catch invalid arguements
        printf("ERROR: Invalid arguements\n");
      }
    }
  }
  printSummary(0, 0, 0);
  return 0;
}
