#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "pqueue.h"
#include "pack.h"

typedef struct node NODE;

/**
 * Function counts the distance from leaf to the root
 * O(h)
 * */
int height(NODE *leaf)
{
	int leafHeight = 0;
    while(leaf->parent != NULL)
    {
        leaf = leaf->parent;
        leafHeight++;
    }
   	return leafHeight;
}

/**
 * Function compartes the data in two nodes
 * O(1)
 * */
int compare(NODE *first, NODE *second)
{
	return (first->count < second->count) ? -1 : (first->count > second->count);
}


int main(int argc, char *argv[])
{
	//Opens and reads each char in file assigning use numbers to array
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
        return 0;
    int index[257] = {0};
    int ch;
    while(1)
    {
        ch = fgetc(fp);
        if(feof(fp))
           	break;
        index[ch]++;
    }

    //Creates the priority queue
    PQ *pq = createQueue(compare);
    NODE *leaves[257] = {0};
    int i;
    for(i = 0; i < 257; i++)
        leaves[i] = NULL;
    for(i = 0; i < 257; i++)
    {
        if(index[i] > 0)
        {
            NODE *p = malloc(sizeof(NODE));
            p->count = index[i];
            p->parent = NULL;
            addEntry(pq, p);
            leaves[i] = p;
        }
    }

    //Add node to last slot
    NODE *end = malloc(sizeof(NODE));
    end->count = 0;
    end->parent = NULL;
    addEntry(pq, end);
    leaves[256] = end; 

    //Combines lowest priority trees to one until huffman tree is left
    while(numEntries(pq) > 1)
    {
	    NODE *one = removeEntry(pq);
		NODE *two = removeEntry(pq);
		NODE *three = malloc(sizeof(NODE));
		three->count = (one->count + two->count);
		three->parent = NULL;
		one->parent = three; 
		two->parent = three;
		addEntry(pq, three); 
    }

    //Prints out vaild nodes
    for(i = 0; i < 257; i++)
    {
        if(leaves[i] != NULL)
        {
            int leafHeight = height(leaves[i]);
            if(isprint(i))
            {
                printf("%c: %d x %d bits = %d bits\n", i, index[i], leafHeight, leafHeight*index[i]);
            }
            else
            {
                printf("%03o: %d x %d bits = %d bits\n", i, index[i], leafHeight, leafHeight*index[i]);
            }
        }
    }

    //Packs huffman tree 
    pack(argv[1], argv[2], leaves);

	return 0;
}