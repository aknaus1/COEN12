/*
 * File: dataset.c
 *
 * COEN 12 Term Project, Application 3
 * 
 * Author: Andrew Knaus
 * School: Santa Clara University
 * Date Published: 3/15/2019
 * 
 * Application 3
 * Description: Assume  a  new college  that  is  expanding  frequently
 *      and  dramatically  on  its  student  amount.  This  leads  to  two  consequences.
 *      First,  accurately  estimating  the  total  number  of  students  is  extremely  difficult.
 *      Second,  frequent insertions and deletions are performed.
 *      In addition, the college frequently requires calculating the largest age gap among  its  students.
 *      Assume  that  search  operations  are  not  performed  frequently.
 *      Your  implementation  has  to  support  searches  on  either  student ID  or  age.
 *      The  major  interfaces  provided  by  your  code  should include
 *      createDataSet, destroyDataSet, searchAge,  searchID,  insertion, deletion, maxAgeGap.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "college.h"

typedef struct node
{
    int age;
    int ID;    
    struct node *next, *prev;
}NODE;

typedef struct set
{
    NODE *head;
    int count;
}SET;

/*
 * Function: createDataSet()
 * 
 * Complexity: O(1)
 * 
 * Description: Return pointer to new set pointed to by SP
 * 
 */
SET *createDataSet()
{
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp->count = 0;
    sp->head = malloc(sizeof(NODE));
    assert(sp->head != NULL);
    sp->head->next = sp->head;
    sp->head->prev = sp->head;
    return sp;
}

/*
 * Function: destroyDataSet()
 * 
 * Complexity: O(n)
 * 
 * Description: Deallocate memory associated with the set pointed to by SP.
 * 
 */
void destroyDataSet(SET *sp)
{
    assert(sp != NULL);
    NODE *pNext, *pDel;
    pDel = pNext = sp->head->next;
    while(pDel != sp->head)
    {
        pNext = pDel->next;
        free(pDel);
        pDel = pNext;
    }
    free(sp);
}

/*
 * Function: searchAge()
 * 
 * Complexity: O(1)
 * 
 * Description: Check if student with age: age is in the set pointed to by SP.
 * 
 */
void searchAge(SET *sp, int age)
{
    assert(sp != NULL);
    printf("Searching for students aged: %d.\n", age);
    NODE *np;
    np = sp->head->next;
    int i;
    for(i = 0; i < sp->count; i++)
    {
        if(np->age == age)
        {
            printf("Student with age %d has been found.\n", age);
            return;
        }
        np = np->next;
    }
    printf("Student has not been found.\n");
}

/*
 * Function: searchID()
 * 
 * Complexity: O(n)
 * 
 * Description: Check if student with id: studentID is in the set pointed to by SP. 
 *      Returns student node if found in set pointed to by sp
 * 
 */
void *searchID(SET *sp, int studentID)
{
    assert(sp != NULL);
    printf("Searching for student: %d.\n", studentID);
    NODE *np;
    np = sp->head->next;
    int i;
    for(i = 0; i < sp->count; i++)
    {
        if(np->ID == studentID)
        {
            printf("Student with ID %d has been found.\n", studentID);
            return np;
        }
        np = np->next;
    }
    printf("Student has not been found.\n");
    return NULL;
}

/*
 * Function: insertion
 * 
 * Complexity: O(n)
 * 
 * Description: Insert new node with age: age and ID: studentID to set pointed to by SP
 * 
 */
void insertion(SET *sp, int studentID, int age)
{
    assert(sp != NULL);
    printf("Inserting student with ID: %d, and age: %d.\n", studentID, age);
    NODE *np, *temp;
    np = malloc(sizeof(NODE));
    np->ID = studentID;
    np->age = age;
    temp = sp->head;
    int i;
    for(i = 0; i < sp->count; i++)
    {
        if(temp->next->age > age)
            break;
        temp = temp->next;
    }
    np->next = temp->next;
    np->prev = temp;
    temp->next->prev = np;
    temp->next = np;
    sp->count++;
    printf("Student has been added successfully.\n");
}

/*
 * Function: deletion()
 * 
 * Complexity: O(1)
 * 
 * Description: Remove student with ID: studentID from set pointed to by SP
 * 
 */
void deletion(SET *sp, int studentID)
{
    printf("Removing students with ID: %d.\n", studentID);
    assert(sp != NULL);
    NODE *np = searchID(sp, studentID);
    if(np == NULL)
        return;
    np->prev->next = np->next;
    np->next->prev = np->prev;
    free(np);
    printf("Student has been removed successfully.\n");
}

/*
 * Function: maxAgeGap()
 * 
 * Complexity: O(1)
 * 
 * Description: Returns the difference in age between the youngest and the oldest student
 * 
 */
void maxAgeGap(SET *sp)
{
    assert(sp != NULL);
    int ageGap = (sp->head->prev->age) - (sp->head->next->age);
    printf("The maximum age gap is %d years.\n", ageGap);
}