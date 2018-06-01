#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

/* Daniel J. Bernstein's "times 33" string hash function, from comp.lang.C;
   See https://groups.google.com/forum/#!topic/comp.lang.c/lSKWXiuNOAk */
unsigned long hash(char *str) { //Creates the hash implementation DO NOT TOUCH
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash;
}

hashtable_t *make_hashtable(unsigned long size) { //Creating a hashtable
  hashtable_t *ht = malloc(sizeof(hashtable_t)); //Memory allocate enough space for the hashtable
  ht->size = size; //Insert size value (metadata)
  ht->buckets = calloc(sizeof(bucket_t *), size); //Memory allocate space for each array(bucket)
  return ht; //Return hashtable_t object (this is a pointer too)
}

void ht_put(hashtable_t *ht, char *key, void *val) { // Create (or update) a node based on the key
  /* FIXME: the current implementation doesn't update existing entries */
  //I need to look for the key, if found, I need to update change the value (change value pointer to new value pointer)
  //If the key does not exist, I need to create a new 'node' with the key/value pair
  unsigned int idx = hash(key) % ht->size; //Find what array(bucket) this key will go to
  if (ht_get(ht, key)) {  // if not null AKA the key already exists
    bucket_t *b = ht->buckets[idx]; // get bucket address and assign to b
    while(b) {  // while b is not null
      if (strcmp(b->key, key) == 0) { // if the keys match
        b->val = val;  // change node value
        break;  // break out of while loop
      }
      b = b->next; // go on to next node
    }
  }
  else {
    bucket_t *b = malloc(sizeof(bucket_t)); //Allocate memory for the key/value pair
    b->key = key; //Insert the key into the allocated memory
    b->val = val; //Insert the value into the allocated memory as well
    b->next = ht->buckets[idx]; //Assign the next key/value pair to be the existing head of the bucket
    ht->buckets[idx] = b; //Make this new key/value pair the next head of the bucket
  }
}

void *ht_get(hashtable_t *ht, char *key) { // Retrieve the value for the key (if it exists)
  unsigned int idx = hash(key) % ht->size; //Find which bucket array the key can be found
  bucket_t *b = ht->buckets[idx]; //Get bucket array
  while (b) { //Checking if not null
    if (strcmp(b->key, key) == 0) { //Check if the key matches what is being evaluated
      return b->val; //Return the value
    }
    b = b->next; //Not the key, looking for next key
  }
  return NULL; //Couldn't find the key, returing NULL
}

void ht_iter(hashtable_t *ht, int (*f)(char *, void *)) { //Iterate throught the hastable (what is this for?)
  bucket_t *b; // pointer of bucket_t
  unsigned long i; // integer declared.  Used for the for loop
  for (i=0; i<ht->size; i++) { // Go through the hastable
    b = ht->buckets[i]; // Assign address of the bucket to b
    while (b) { // While be is not null
      if (!f(b->key, b->val)) { // Execute function f with the key and value pair
        return ; // abort iteration
      }
      b = b->next; // go to next node
    }
  }
}

void free_hashtable(hashtable_t *ht) {
  free(ht); // FIXME: must free all substructures!
  // We need to iterate through the hashtable
  // ht_iter will allow us to free the nodes in each bucket
}

/* TODO */
void  ht_del(hashtable_t *ht, char *key) { // Remove the key from the hashtable
  // Hash the key and find index for the bucket
  // Create an integer of 0 to go through the bucket
  // While loop that verifies that the next node is not null
    // If the next node is the target
      //Assign the current node's next to be the target node's next
      //Free the memory that was used for the target node
      //Break from loop
    // Else Increment integer by 1
}

void  ht_rehash(hashtable_t *ht, unsigned long newsize) {
  hashtable_t *newTable = make_hashtable(newsize); // create new hashtable (allocate size) and assign it to ht
  bucket_t *b; // create bucket variable
  unsigned long i; // create counter
  for (i=0; i<ht->size; i++) { // iterate through the hashtable
    b = ht->buckets[i]; // assign the bucket to be
    while (b) { // while b is not null
      ht_put(newTable, b->key, b->val); // put the key/value pair into the new hashtable
      b = b->next; // go to next node
    }
  }
  ht = newTable;
  // TODO: Free newTable
}