/*
 * File: dataset.c
 *
 * COEN 12 Term Project, Application 2
 * 
 * Author: Andrew Knaus
 * School: Santa Clara University
 * Date Published: 3/15/2019
 * 
 * Application 2
 * Description: Assume  that  the  college  takes  very  few  transfer  students
 *      and  has  most  of  its  students  stay  for  at  least  one  year
 *      (Hints: no  frequent  insertion  and  deletion  operations).
 *      And  the  maximum  student  number  is  given.  But  it  does  require  a  lot  of  search  operations.
 *      Specifically,  all  of  the  searches are  based  on  student  IDs.
 *      The  major  interfaces  provided by your code should include createDataSet,
 *      destroyDataSet, searchID, insertion, deletion.  
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define EMPTY 0
#define FILLED 1
#define DELETED 2

typedef struct set
{
    int count;
    int length;
    int *age;
    char *flag;
}SET;

/*
 * Function: createDataSet()
 * 
 * Complexity: O(n)
 * 
 * Description: Return pointer to new set SP with maximum capacity of maxStudents
 * 
 */
SET *createDataSet(int maxStudents)
{
    SET *sp = malloc(sizeof(SET));
    assert(sp != NULL);
    sp->age = malloc(sizeof(int)*maxStudents);
    assert(sp->age != NULL);
    sp->flag = malloc(sizeof(char)*maxStudents);
    assert(sp->flag != NULL);
    sp->count = 0;
    sp->length = maxStudents;
    int i;
    for(i = 0; i < maxStudents; i++)
		sp->flag[i] = EMPTY;
    return sp;
}

/*
 * Function: destroyDataSet()
 * 
 * Complexity: O(1)
 * 
 * Description: Deallocate memory associated with the set pointed to by SP.
 * 
 */
void destroyDataSet(SET *sp)
{
    assert(sp != NULL);
    free(sp->age);
    free(sp->flag);
    free(sp);
}

/*
 * Function: searchID()
 * 
 * Complexity: O(1)
 * 
 * Description: Check if student with id: studentID is in the set pointed to by SP.
 * 
 */
void searchID(SET *sp, int studentID)
{
    printf("Searching for student: %d\n", studentID);
    if(sp->flag[studentID] == FILLED)
        printf("Student: %d has been found.\n", studentID);
    else
        printf("Student: %d has not been found.\n", studentID);
}

/*
 * Function: insertion()
 * 
 * Complexity: O(1)
 * 
 * Description: Insert new node with age: age and ID: studentID to set pointed to by SP
 * 
 */
void insertion(SET *sp, int studentID, int age)
{
    printf("Inserting student: %d, and age: %d.\n", studentID, age);
    if(sp->flag[studentID] == FILLED)
    {
        printf("There is already a student with ID: %d\n", studentID);
        return;
    }
    sp->age[studentID] = age;
    sp->flag[studentID] = FILLED;
    sp->count++;
    printf("Student: %d has been added successfully.\n", studentID);
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
    printf("Removing student: %d.\n", studentID);
    if(sp->flag[studentID] == FILLED)
    {
        sp->flag[studentID] = DELETED;
        sp->age[studentID] = '\0';
        printf("Student: %d has been removed successfully.\n", studentID);
        return;
    }
    printf("Student: %d was not found.\n", studentID);
}