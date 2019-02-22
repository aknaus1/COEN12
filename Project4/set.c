#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

typedef struct node NODE;
typedef struct list LIST;
typedef struct set SET;

struct node
{
    void *data;
    NODE *next, *prev;
};

struct list
{
    NODE *head;
    int count;
    int (*compare)(); 
};

struct set
{
	LIST **lists;
	int count;
	int length;
	int (*compare)();
	unsigned (*hash)();
};

/**
 * return a pointer to a new list using compare as its comparison function, which may be NULL
 * O(1)
 * */
SET *createSet(int maxElts, int (*compare)(), unsigned (*hash)())
{
    int i;
    SET *sp;
    assert(compare != NULL && hash != NULL);
    sp = malloc(sizeof(SET));
    assert(sp != NULL);    
    sp->count = 0;
    sp->length = maxElts;
    sp->compare = compare;
    sp->hash = hash;
    sp->lists = malloc(sizeof(LIST*) *sp->length);
    for(i = 0; i < sp->length; i++)
        sp->lists[i] = createList(compare);
    return sp;
}

/**
 * deallocate memory associated with the list pointed to by sp
 * O(n)
 * */
void destroySet(SET *sp)
{
    assert(sp != NULL);
    int i;
    for(i = 0; i < sp->length; i++)
        free(sp->lists[i]);
    free(sp->lists);
    free(sp);
}

/**
 * return the number of elts in the list pointed to by sp
 * O(1)
 * */
int numElements(SET *sp)
{
    assert(sp != NULL);
    return sp->count;
}

/**
 * add elt as the first elt in the list pointed to by sp
 * O(1)
 * */
void addElement(SET *sp, void *elt)
{
    assert(sp != NULL && elt != NULL);
    int index = (*sp->hash)(elt) % sp->length;
    if(findItem(sp->lists[index], elt) == NULL)
    {
        addFirst(sp->lists[index], elt);
        sp->count++;
    }
}

/**
 * if elt is present in the list pointed to by sp then remove it;
 * the comparison function must not be NULL
 * O(n)
 * */
void removeElement(SET *sp, void *elt)
{
    assert(sp != NULL && elt != NULL);
    int index = (*sp->hash)(elt) % sp->length;
    if(findItem(sp->lists[index], elt) != NULL)
    {
        removeItem(sp->lists[index], elt);
        sp->count--;
    }
}

/**
 * if elt is present in the list pointed to by sp then return the matching elt,
 * otherwise return NULL; the comparison function must not be NULL
 * O(n)
 * */
void *findElement(SET *sp, void *elt)
{
    assert(sp != NULL && elt != NULL);
    int index = (*sp->hash)(elt) % sp->length;
    return findItem(sp->lists[index], elt);
}

/**
 * allocate and return an array of elts in the list pointed to by sp
 * O(n)
 * */
void *getElements(SET *sp)
{
    assert(sp != NULL);
    void **arg = malloc(sizeof(void*)*sp->count);
    NODE *p = malloc(sizeof(NODE));
    int i, j = 0;
    for(i=0; i < sp->count; i++)
    {
        if(numItems(sp->lists[i]) > 0)
        {
            p=sp->lists[i]->head->next;
            while(p != sp->lists[i]->head)
            {
                arg[j] = p->data;
                j++;
                p = p->next;
            }
        }
    }
    return arg;
}