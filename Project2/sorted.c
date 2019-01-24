/**
 * Second, implement a set using a sorted array of lengthm>0,
 * in which the firstn≤mslots are used to holdnstrings in ascending order. 
 * Use binary search to locate an elementin the array.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "set.h"
int hasElement(SET *sp, char *elt);

struct set {
    int count; //Number of elements
	int length; //Size of array
    char **data;
};

//Return a pointer to a new set with a maximum capacity ofmaxElts
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

//Deallocate memory associated with the set pointed to by sp
void destroySet(SET *sp)
{
    int i;
    assert(sp != NULL);
    for(i = 0; i < sp->count; i++)
        free(sp->data[i]); //Frees indexes of element
    free(sp->data); //Frees element
    free(sp); //Frees pointer to element
};

//Return the number of elements in the set pointed to by sp
int numElements(SET *sp)
{
    assert(sp != NULL);
	return(sp->count);
}

//Add elt to the set pointed to by sp
void addElement(SET *sp, char *elt)
{
    if(sp->count == sp->length)
        return;
    sp->data[sp->count] = strdup(elt);
    (sp->count)++;
}

//Remove elt from the set pointed to by sp
void removeElement(SET *sp, char *elt)
{
    char *temp = findElement(sp, elt);
	assert(sp != NULL);
	assert(elt != NULL);
    if (temp != NULL)//If element is found
	{ 
		free(temp); //Free element
		(sp->count)--; //Corrects set count
	}
    return;
}

//If elt is present in the set pointed to by sp then return the matching element, otherwise return NULL
char *findElement(SET *sp, char *elt)
{
    int i;
	assert(sp != NULL);
    int temp = hasElement(sp, elt);
	if (temp != -1)
		return(sp->data[temp]); //Return element
    return NULL;
}

//Allocate and return an array of elements in the set pointed to by sp
char **getElements(SET *sp)
{
    int i;
    char set[sp->count];
    char **ap;
    ap = malloc(sizeof (sp));
    ap = sp->data;
    return ap;
}

//Returns true if set has the element, else false
int hasElement(SET *sp, char *elt)
{
    int i, found = -1;
	for (i = 0; i < sp->count; i++)
	{
		if (strcmp(sp->data[i], elt) == 0) 
			found = i;
    }
	return found;
}