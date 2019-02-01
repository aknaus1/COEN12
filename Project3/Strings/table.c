/**
 * Implement a set using a hash table of length m>0 and linear probing to resolve collisions.  
 * Create an auxiliaryfunctionsearchthat contains all of the search logic as you did for the previous assignment, 
 * and usesearchtoimplement the functions in your interface. 
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
	char **data;
	char *flags; //array of flags to track status of a location
};

/**
 * Return a pointer to a new set with a maximum capacity of maxElts
 * */
SET*createSet(int maxElts)
{
    int i;
    SET *sp;
    sp = malloc(sizeof (SET));
    assert(sp != NULL);
    sp->count = 0;
    sp->length = maxElts;
    sp->data = malloc(sizeof (char *) *maxElts);
    assert(sp->data != NULL);
    sp->flags = malloc(sizeof(char)*maxElts);
	assert(sp->flags != NULL);
	for(i = 0;i < maxElts;i++)
		sp->flags[i] = EMPTY;
    return sp;
}

unsigned strhash(char*s) 
{
	unsigned hash = 0;
	while (*s != '\0')
		hash = 31*hash +*s ++;
	return hash;
}

/**
 * Find index of element in set sp
 * */
int search(SET*sp, char*elt, bool*found)
{
	int i, lastIndex, flag = 0, first;
	assert(sp != NULL);
	assert(elt != NULL);
	unsigned index = (strhash(elt) % sp->length);
	for(i = 0;i < sp->length; i++)
	{
		if(sp->flags[index]==FILLED && strcmp(sp->data[index],elt) == 0)
		{
			*found = true;
			return index;
		}
		else if(sp->flags[index]==EMPTY)
		{
			*found = false;
			if(flag==1)
				return first;
			return index;
		}
		else if(sp->flags[index]==DELETED)
		{
			if(flag==0)
			{
				first = index;
				flag++;
			}
		}
		index++;
		index = index%sp->length;
	}
	return -1;
}

/**
 * Deallocate memory associated with the set pointed to by sp
 * */
void destroySet(SET*sp)
{
    int i;
	assert(sp != NULL);
	for(i = 0;i < sp->length;i++)
	{
		if(sp->flags[i] == FILLED)
			free(sp->data[i]);
	}
	free(sp->data);
	free(sp);
	return;
}

/**
 * Return the number of elements in the set pointed to by sp
 * */
int numElements(SET*sp)
{
    assert(sp != NULL);
	return sp->count;
}

/**
 * Add elt to the set pointed to by sp
 * */
void addElement(SET*sp, char*elt)
{
	assert(sp != NULL);
	bool found;
	int index = search(sp, elt, &found);
	if(found == true)
		return;
	sp->data[index] = strdup(elt);
	sp->flags[index] = FILLED;
	sp->count++;
	return;
}

/**
 * remove elt from the set pointed to by sp
 * */
void removeElement(SET*sp, char*elt)
{
	assert(sp != NULL);
	bool found;
	int index = search(sp, elt, &found);
	if(found == false)
		return;
	sp->flags[index] = DELETED;
	free(sp->data[index]);
	sp->count--;
	return;
}

/**
 * If elt is present in the set pointed to byspthen return the matching element, 
 * otherwise return NULL
 * */
char *findElement(SET*sp, char*elt)
{
	assert(sp != NULL);
	bool found;
	int index = search(sp, elt, &found);
	if(found == false)
		return NULL;
	return sp->data[index];
}

/**
 * Allocate and return an array of elements in the set pointed to by sp
 * */
char **getElements(SET*sp)
{
	char**elts;
	assert(sp != NULL);
	elts = malloc(sizeof(char *) * sp->count);
	assert(elts != NULL);
	return memcpy(elts, sp->data, sizeof(char *) * sp->count);
}