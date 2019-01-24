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
    int i, low = 0, mid, high = (sp->count-1);
    assert(sp != NULL);
    while(low<=high)
    {
        mid = (low+high)/2;
        if(strcmp(sp->data[mid], elt) == 0)
            return sp->data[mid];
        else if(strcmp(sp->data[mid], elt) > 0)
            high = (mid-1);
        else
            low = (mid+1);
    }
    for(i = (sp->count); i > mid; i--)
        sp->data[i] = sp->data[i-1];
    sp->data[mid] = strdup(elt);
    (sp->count)++;
}

//Remove elt from the set pointed to by sp
void removeElement(SET *sp, char *elt)
{
    int i;
	assert(sp != NULL);
    char *temp = findElement(sp, elt);
    if(temp == NULL)
        return;
    free(temp); //Free element
    if (sp->count == 1)//If it is the only element
	{ 
		(sp->count)--; //Corrects set count
        return;
	}
    int index = hasElement(sp, elt);
    for(i = index; i < sp->count-1; i++)
        sp->data[i] = sp->data[i+1];
    (sp->count)--;
    return;
}

//If elt is present in the set pointed to by sp then return the matching element, otherwise return NULL
char *findElement(SET *sp, char *elt)
{
    int low = 0, mid, high = (sp->count-1);
	assert(sp != NULL);
    while(low<=high)
    {
        mid = (low+high)/2;
        if(strcmp(sp->data[mid], elt) == 0)
            return sp->data[mid];
        else if(strcmp(sp->data[mid], elt) > 0)
            high = (mid-1);
        else
            low = (mid+1);
    }
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