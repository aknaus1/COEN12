/**
 * First, implement a set using anunsorted array of lengthm>0, 
 * in which the firstn≤mslots are used to holdnstrings in some arbitrary order. 
 * Usesequential search to locate an element in the array. 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "set.h"

struct set {
    int count; //Number of elements
	int length; //Size of array
    char **data;
};

/**
 * Return a pointer to a new set with a maximum capacity ofmaxElts
 * Big O: O(1)
 * */
SET *createSet(int maxElts)
{
    SET *sp;
    sp = malloc(sizeof (SET));
    assert(sp != NULL);
    sp->count = 0;
    sp->length = maxElts;
    sp->data = malloc(sizeof (char *) *maxElts);
    assert(sp->data != NULL);
    return sp;
};

int search(SET *sp, char *elt){
    int i;
    assert(sp != NULL);
    for (i = 0; i < sp->count; i++)
	{
		if (strcmp(sp->data[i], elt) == 0) 
        {
            return i;
        }
    }
    return -1;
}

/**
 * Deallocate memory associated with the set pointed to by sp
 * Big O: O(n)
 * */
void destroySet(SET *sp)
{
    int i;
    assert(sp != NULL);
    for(i = 0; i < sp->count; i++)
        free(sp->data[i]); //Frees indexes of element
    free(sp->data); //Frees element
    free(sp); //Frees pointer to element
};

/**
 * Return the number of elements in the set pointed to by sp
 * Big O: O(1);
 * */
int numElements(SET *sp)
{
	return(sp->count);
}

/**
 * Add elt to the set pointed to by sp
 * Big O: O(1)
 * */
void addElement(SET *sp, char *elt)
{
    if(sp->count == sp->length)
        return;
    if (findElement(sp, elt) == NULL)
    {
        sp->data[sp->count] = strdup(elt);
        (sp->count)++;
    }
}

/**
 * Remove elt from the set pointed to by sp
 * Big O: O(1)
 * */
void removeElement(SET *sp, char *elt)
{
    int i, index;
    assert(sp != NULL);
    index = search(sp, elt);
    if (index != -1)//If element is found
	{ 
	    free(sp->data[index]); //Free element
        for(i = index; i < (sp->count-1); i++) //Shifts the array
            sp->data[i] = sp->data[i+1];
		(sp->count)--; //Corrects set count
	}
    return;
}

/**
 * If elt is present in the set pointed to by sp then return the matching element, otherwise return NULL
 * Big O: O(n)
 * */
char *findElement(SET *sp, char *elt)
{
    int index = search(sp, elt);
	if (index != -1) 
		return(sp->data[index]);
    return NULL;
}

/**
 * Allocate and return an array of elements in the set pointed to by sp
 * Big O: O(1)
 * */
char **getElements(SET *sp)
{
    char**elts;
	assert(sp != NULL);
	elts = malloc(sizeof(char *) * sp->count);
	assert(elts != NULL);
	return memcpy(elts, sp->data, sizeof(char *) * sp->count);
}