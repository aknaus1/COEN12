/**
 * Application 2
 * Description: Assume  that  the  college  takes  very  few  transfer  students
 *      and  has  most  of  its  students  stay  for  at  least  one  year
 *      (Hints: no  frequent  insertion  and  deletion  operations).
 *      And  the  maximum  student  number  is  given.  But  it  does  require  a  lot  of  search  operations.
 *      Specifically,  all  of  the  searches are  based  on  student  IDs.
 *      The  major  interfaces  provided by your code should include createDataSet,
 *      destroyDataSet, searchID, insertion, deletion.  
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "college.h"

#define maxStudents 3000

int randID()
{
    int ID = 1;
    ID += (rand()%2);
    return ID;
}

int randAge()
{
    int age = 18;
    age += (rand()%13);
    return age;
}

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