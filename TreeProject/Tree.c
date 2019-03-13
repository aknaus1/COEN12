#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef struct tree
{
    void *data;
    struct tree *left, *right;
}TREE;

void *getValue(TREE tp)
{
    assert(tp != NULL);
    return tp->data;
}

void insert(TREE *tp, void *data)
{
    assert(tp != NULL && data != NULL);
    if(tp->data == NULL)
    {
        tp->data = data;
        return;
    }
    else if(tp->data > data)
    {
        insert(tp->right, data);
        return;
    }
    else if(tp->data < data)
    {
        insert(tp->left, data);
        return;
    }
}

void *findItem(TREE *tp, void *data)
{
    assert(tp != NULL && data != NULL);
    if(tp->data == NULL)
    {
        return NULL;
    }
    else if(tp->data == data)
    {
        return tp;
    }
    else if(tp->data > data)
    {
        return findItem(tp->left, data);
    }
    else if(tp->data < data)
    {
        return findItem(tp->right, data);
    }
}

void *remove(TREE *tp, void *data)
{
    assert(tp != NULL && data != NULL);
    TREE *item;
    tp = findItem(tp, data);
    if(tp != NULL)
    {
        item = tp;
        if(tp->right == NULL)
        {
            tp = tp->left;
            while(tp->right != NULL)
                tp = tp->right;
        }
        else if(tp->left == NULL || tp->right->left == NULL || tp->right->right == NULL)
        {
            tp = tp->right;
            while(tp->left != NULL)
                tp = tp->left;
        }
        item->data = tp->data;
        free(tp);
    }

}