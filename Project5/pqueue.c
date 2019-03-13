#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "pqueue.h"

#define START 10
#define p(x) (((x)-1)/2)
#define l(x) (((x)*2)+1)
#define r(x) (((x)*2)+2)

struct pqueue
{
    int count;
    int length;
    void **data;
    int (*compare)();
};


/**
 * Return a pointer to a new priority queue using compare as its comparison function
 * O(1)
 * */
PQ *createQueue(int (*compare)())
{
    assert(compare != NULL);
    PQ *pq;
    pq = malloc(sizeof(PQ));
    assert(pq != NULL);
    pq->count = 0;
    pq->length = START;
    pq->compare = compare;
    pq->data = malloc(sizeof(void*)*START);
    return pq;
}

/**
 * Deallocate memory associated with the priority queue pointed to by pq
 * O(1)
 * */
void destroyQueue(PQ *pq)
{
    assert(pq != NULL);
    free(pq->data);
    free(pq);
}

/**
 * Return the number of entries in the priority queue pointed to by pq
 * O(1)
 * */
int numEntries(PQ *pq)
{
    assert(pq != NULL);
    return pq->count;
}

/**
 * Add entry to the priority queue pointed to by pq
 * O(log(n))
 * */
void addEntry(PQ *pq, void *entry)
{
    assert(pq != NULL && entry != NULL);
    if(pq->count == pq->length)
    {
        pq->data = realloc(pq->data, sizeof(void*)*pq->length*2);
        pq->length *= 2;
    }
    pq->data[pq->count] = entry;
    int loc = pq->count; 
    while(pq->compare(pq->data[loc], pq->data[p(loc)]) < 0)
    {
        void *temp = pq->data[p(loc)];
        pq->data[p(loc)] = pq->data[loc];
        pq->data[loc] = temp; 
    }
    pq->count++;
}

/**
 * Remove and return the smallest entry from the priority queue pointed to by pq
 * O(log(n))
 * */
void *removeEntry(PQ *pq)
{
    assert(pq != NULL);
    int loc = 0, small = 0; 
    void *root = pq->data[0];
    pq->data[loc] = pq->data[pq->count - 1];
    pq->count--;
    while(l(loc) < pq->count)
    {
        small = l(loc);
        if(r(loc) < pq->count)
        {
            if(pq->compare(pq->data[l(loc)] , pq->data[r(loc)]) < 0)
                small = l(loc); 
            else 
                small = r(loc); 
        }
        if(pq->compare(pq->data[small],pq->data[loc]) < 0)
        {
            void *temp = pq->data[small]; 
            pq->data[small] = pq->data[loc];
            pq->data[loc] = temp; 
            loc = small; 
        }
        else
            break;
    } 
    return root; 
}