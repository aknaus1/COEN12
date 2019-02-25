#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

typedef struct node
{
    void *data;
    struct node *next;
    struct node *prev;
}NODE;

typedef struct list
{
    int count;
    NODE *head;
    int (*compare)(); 
}LIST;

/**
 * return a pointer to a new list using compare as its comparison function, which may be NULL
 * O(1)
 * */
LIST *createList(int (*compare)())
{
    LIST *lp;
    lp = malloc(sizeof(LIST));
    assert(lp != NULL);
    lp->count = 0;
    lp->compare = compare;
    lp->head = malloc(sizeof(NODE));
    assert(lp->head != NULL);
    lp->head->next = lp->head;
    lp->head->prev = lp->head;
    return lp;
}

/**
 * deallocate memory associated with the list pointed to by lp
 * O(n)
 * */
void destroyList(LIST *lp)
{
    assert(lp != NULL);
    NODE *pDel = lp->head->prev;
    NODE *pPrev;
    while(pDel != lp->head)
    {
        pPrev = pDel->prev;
        free(pDel);
        pDel = pPrev;
    }
    free(pDel);
    free(lp);
    return;
}

/**
 * return the number of items in the list pointed to by lp
 * O(1)
 * */
int numItems(LIST *lp)
{
    assert(lp != NULL);
    return lp->count;
}

/**
 * add item as the first item in the list pointed to by lp
 * O(1)
 * */
void addFirst(LIST *lp, void *item)
{
    assert(lp != NULL && item != NULL);
    NODE *p = malloc(sizeof(NODE));;
    p->data = item;
    p->next = lp->head->next;
    p->prev = lp->head;
    lp->head->next = p;
    p->next->prev = p;
    lp->count++;
    return;
}

/**
 * add item as the last item in the list pointed to by lp
 * O(1)
 * */
void addLast(LIST *lp, void *item)
{
    assert(lp != NULL && item != NULL);
    NODE *p = malloc(sizeof(NODE));
    p->data = item;
    p->prev = lp->head->prev;
    p->next = lp->head;
    lp->head->prev->next = p;
    lp->head->prev = p;
    lp->count++;
    return;
}

/**
 * remove and return the first item in the list pointed to by lp;
 * the list must not be empty
 * O(1)
 * */
void *removeFirst(LIST *lp)
{
    assert(lp->count > 0);
    void *tempData;
    NODE *temp = malloc(sizeof(NODE));
    temp = lp->head->next;
    lp->head->next = temp->next;
    temp->next->prev = lp->head;
    lp->count--;
    tempData = temp->data;
    free(temp);
    return tempData;
}

/**
 * remove and return the last item in the list pointed to by lp;
 * the list must not be empty
 * O(1)
 * */
void *removeLast(LIST *lp)
{
    assert(lp->count > 0);
    void *tempData;
    NODE *temp = malloc(sizeof(NODE));
    temp = lp->head->prev;
    temp->prev->next = lp->head;
    lp->head->prev = temp->prev;
    lp->count--;
    tempData = temp->data;
    free(temp);
    return tempData;
}

/**
 * return, but do not remove, the first item in the list pointed to by lp;
 * the list must not be empty
 * O(1)
 * */
void *getFirst(LIST *lp)
{
    assert(lp->count > 0);
    return (lp->head->next->data);
}

/**
 * return, but do not remove, the last item in the list pointed to by lp;
 * the list must not be empty
 * O(1)
 * */
void *getLast(LIST *lp)
{
    assert(lp->count > 0);
    return (lp->head->prev->data);
}

/**
 * if item is present in the list pointed to by lp then remove it;
 * the comparison function must not be NULL
 * O(n)
 * */
void removeItem(LIST *lp, void *item)
{
    assert(lp != NULL && lp->compare != NULL);
    int i;
    NODE *p = malloc(sizeof(NODE));
    p = lp->head->next;
    for(i=0; i < lp->count; i++)
    {
        if(((lp->compare)(p->data , item)) == 0)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            lp->count--;
            return;
        }
        else
            p = p->next;
    }
    return;
}

/**
 * if item is present in the list pointed to by lp then return the matching item,
 * otherwise return NULL; the comparison function must not be NULL
 * O(n)
 * */
void *findItem(LIST *lp, void *item)
{
    int i;
    assert(lp != NULL && lp->compare != NULL);
    NODE *p = malloc(sizeof(NODE));
    p = lp->head->next;
    for(i=0; i < lp->count; i++)
    {
        if(((lp->compare)(p->data,item)) == 0)
            return p->data;
        else
            p = p->next;
    }
    return NULL;
}

/**
 * allocate and return an array of items in the list pointed to by lp
 * O(n)
 * */
void *getItems(LIST *lp)
{
    assert(lp != NULL);
    void **arg = malloc(sizeof(void*)*lp->count);
    int i;
    NODE *p = lp->head->next;
    for(i=0; i < lp->count; i++)
    {
        arg[i] = p->data;
        p = p->next;
    }
    return arg;
}