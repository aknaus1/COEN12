/**
 * Implement a set using a hash table of length m>0 and linear probing to resolve collisions.  
 * Create an auxiliary function search that contains all of the search logic as you did for the previous assignment, 
 * and use search to implement the functions in your interface. 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "set.h"

#define EMPTY 0
#define FILLED 1
#define DELETED 2

struct set
{
	int count;
	int length;
	void **data;
	char *flags; //array of flags to track status of a location
    int (*compare)();
    unsigned (*hash)();
};

/**
 * Return a pointer to a new set with a maximum capacity of maxElts
 * O(n)
 * */
SET*createSet(int maxElts, int (*compare)(), unsigned (*hash)())
{
    int i;
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp->count = 0;
    sp->length = maxElts;
    sp->data = malloc(sizeof(void*)*maxElts);
    assert(sp->data != NULL);
    sp->flags = malloc(sizeof(void)*maxElts);
	for(i = 0;i < maxElts;i++)
		sp->flags[i] = EMPTY;
    sp->compare=compare;
    sp->hash=hash;
    return sp;
}

/**
 * Find index of element in set sp
 * O(n)
 * */
int search(SET*sp, void*elt, bool*found)
{
	int i, index, count = 0, first;
	assert(sp != NULL && elt != NULL);
	index = sp->hash(elt)%sp->length;
	for(i = 0;i < sp->length;i++)
	{
		if(sp->flags[index]==FILLED && ((*sp->compare)(sp->data[index], elt)) == 0)
		{
			*found = true;
			return index;
		}
        else if(sp->flags[index]==DELETED && count == 0)
		{
			first = index;
			count++;
		}
		else if(sp->flags[index]==EMPTY)
		{
			*found = false;
			if(count==1)
				return first;
			return index;
		}
        index++;
        index = index%sp->length;
	}
	return -1;
}

/**
 * Deallocate memory associated with the set pointed to by sp
 * O(1)
 * */
void destroySet(SET*sp)
{
    assert(sp != NULL);
	free(sp->data);
    free(sp->flags);
	free(sp);
	return;
}

/**
 * Return the number of elements in the set pointed to by sp
 * O(1)
 * */
int numElements(SET*sp)
{
    assert(sp != NULL);
	return sp->count;
}

/**
 * Add elt to the set pointed to by sp
 * O(n)
 * */
void addElement(SET*sp, void*elt)
{
	assert(sp != NULL && elt != NULL);
	bool found;
	int index = search(sp, elt, &found);
	if(found == true)
		return;
	sp->data[index] = elt;
    assert(sp->data != NULL);
	sp->flags[index] = FILLED;
	sp->count++;
	return;
}

/**
 * remove elt from the set pointed to by sp
 * O(n)
 * */
void removeElement(SET*sp, void*elt)
{
	assert(sp != NULL && elt != NULL);
	bool found;
	int index = search(sp, elt, &found);
	if(found == false)
		return;
	sp->flags[index] = DELETED;
	sp->count--;
	return;
}

/**
 * If elt is present in the set pointed to by sp then return the matching element, 
 * otherwise return NULL
 * O(n)
 * */
void *findElement(SET*sp, void*elt)
{
	assert(sp != NULL && elt != NULL);
	bool found;
	int index = search(sp, elt, &found);
	if(found == false)
		return NULL;
	return sp->data[index];
}

/**
 * Allocate and return an array of elements in the set pointed to by sp
 * O(n)
 * */
void *getElements(SET*sp)
{
    int i, counter = 0;
    void **p;
	assert(sp != NULL);
    p=malloc(sizeof(void*)*sp->count);
    for(i = 0;i < sp->length;i++)
    {
        if(sp->flags[i]==FILLED)
        {
            p[counter] = sp->data[i];
            counter++;
        }
    }
	return p;
}