/*
 * File: college.c
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
#include <time.h>

#include "college.h"

#define maxStudents 3000

/*
 * Function: randID()
 * 
 * Complexity: O(1)
 * 
 * Description: Generate and return a random int ID
 *      Range 1 - 2
 */
int randID()
{
    int ID = 1;
    ID += (rand()%2);
    return ID;
}

/*
 * Function: randAge()
 * 
 * Complexity: O(1)
 * 
 * Description: Generate and return a random int age
 *      Range: 18 - 30
 */
int randAge()
{
    int age = 18;
    age += (rand()%13);
    return age;
}

/*
 * Function: main()
 * 
 * Complexity: O(n)
 */
int main(void)
{
    int i, studentID = 0, age;
    SET *sp = createDataSet(maxStudents);
    srand(time(NULL));
    for(i=0; i<1000; i++)
    {
        studentID += randID();
        age = randAge();
        insertion(sp, studentID, age);
    }
    studentID = 1 + (rand()%2000);
    searchID(sp, studentID);
    studentID = 1 + (rand()%2000);
    deletion(sp, studentID);
    destroyDataSet(sp);
}