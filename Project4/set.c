#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

#define AVG 20 

typedef struct node
{
    void *data;
    struct node *next;
    struct node *prev;
}NODE;

typedef struct list
{
    NODE *head;
    int count;
    int (*compare)(); 
}LIST;

typedef struct set
{
	LIST **lists;
	int count;
	int length;
	int (*compare)();
	unsigned (*hash)();
}SET;

/**
 * return a pointer to a new list using compare as its comparison function, which may be NULL
 * O(n)
 * */
SET *createSet(int maxElts, int (*compare)(), unsigned (*hash)())
{
    //printf("Start createSet\n");
    int i;
    assert(compare != NULL && hash != NULL);
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp->count = 0;
    sp->length = maxElts / AVG;
    sp->compare = compare;
    sp->hash = hash;
    sp->lists = malloc(sizeof(LIST*)*sp->length);
    for(i = 0; i < sp->length; i++)
        sp->lists[i] = createList(compare);
    //printf("End createSet\n");
    return sp;
}

/**
 * deallocate memory associated with the list pointed to by sp
 * O(n)
 * */
void destroySet(SET *sp)
{
    //printf("Start destroySet\n");
    int i;
    assert(sp != NULL);
    for(i = 0; i < sp->length; i++)
        free(sp->lists[i]);
    free(sp->lists);
    free(sp);
    //printf("End destroySet\n");
}

/**
 * return the number of elts in the list pointed to by sp
 * O(1)
 * */
int numElements(SET *sp)
{
    //printf("Start numElements\n");
    assert(sp != NULL);
    //printf("End numElements\n");
    return sp->count;
}

/**
 * add elt as the first elt in the list pointed to by sp
 * O(n)
 * */
void addElement(SET *sp, void *elt)
{
    //printf("Start addElement\n");
    assert(sp != NULL && elt != NULL);
    int index = (*sp->hash)(elt) % sp->length;
    if(findItem(sp->lists[index], elt) == NULL)
    {
        addFirst(sp->lists[index], elt);
        sp->count++;
    }
    //printf("End addElement\n");
}

/**
 * if elt is present in the list pointed to by sp then remove it;
 * the comparison function must not be NULL
 * O(n^2)
 * */
void removeElement(SET *sp, void *elt)
{
    //printf("Start removeElement\n");
    assert(sp != NULL && elt != NULL);
    int index = (*sp->hash)(elt) % sp->length;
    if(findItem(sp->lists[index], elt) != NULL)
    {
        removeItem(sp->lists[index], elt);
        sp->count--;
    }
    //printf("End removeElement\n");
}

/**
 * if elt is present in the list pointed to by sp then return the matching elt,
 * otherwise return NULL; the comparison function must not be NULL
 * O(n)
 * */
void *findElement(SET *sp, void *elt)
{
    //printf("Start findElement\n");
    assert(sp != NULL && elt != NULL);
    int index = (*sp->hash)(elt) % sp->length;
    //printf("End findElement\n");
    return findItem(sp->lists[index], elt);
}

/**
 * allocate and return an array of elts in the list pointed to by sp
 * O(n)
 * */
void *getElements(SET *sp)
{
    //printf("Start getElements\n");
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
    //printf("End getElements\n");
    return arg;
}