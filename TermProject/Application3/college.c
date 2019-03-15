/*
 * File: college.c
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
#include <time.h>

#include "college.h"

/*
 * Function: randID()
 * 
 * Complexity: O(1)
 * 
 * Description: Generate and return a random int ID
 *      Range 1 - 2
 * 
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
 * 
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
 * 
 */
int main(void)
{
    int i, studentID = 0, age;
    SET *sp = createDataSet();
    srand(time(NULL));
    for(i=0; i<1000; i++)
    {
        studentID += randID();
        age = randAge();
        insertion(sp, studentID, age);
    }
    studentID = 1 + (rand()%2000);
    searchID(sp, studentID);
    age = randAge();
    searchAge(sp, age);
    age = randAge();
    studentID = 1 + (rand()%2000);
    deletion(sp, studentID);
    maxAgeGap(sp);
    destroyDataSet(sp);
}