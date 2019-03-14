/**
 * Application 1
 * Description: Assume  that  the  college  takes  very  few  transfer  students
 *   and  has  most  of  its  students  stay  for  at  least  one  year.
 *   (Hints: no  frequent  insertion  and  deletion  operations).
 *   And  the  maximum  student  number  is  given.
 *   But  it  does  require  a  lot  of  search  operations  based  on  student  ages.
 *   Please  note  that  your  search  functions  may  return multiple records when only a student age is given.
 *   In addition, the college often requires calculating the largest age gap among its students.
 *   The major interfaces provided by your code should include createDataSet,
 *   destroyDataSet, searchAge, insertion, deletion, maxAgeGap.  
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "dataset.c"

#define maxStudents 3000

int randID()
{
    int ID = 1;
    ID += (rand()%2);
}

int randAge()
{
    int age = 18;
    age += (rand()%12);
}

int main(void)
{
    int i, studentID = 0, age;
    createDataSet(maxStudents);
    srand(time(NULL));
    for(i=0; i<1000; i++)
    {
        studentID += randID();
        age = randAGE();
        insertion(studentID, age);
    }
    studentID = 1 + (rand()%2000);
    age = randAge();
    searchAge(studentID, age);
    age = randAge();
    deletion(age);
    maxAgeGap();
    destroyDataSet();
}