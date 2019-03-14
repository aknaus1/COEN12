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

typedef struct node
{
    int age;
    int studentID;
    int count;
    int length;
    
}STUDENT;

createDataSet(int maxStudents)
{

}

destroyDataSet()
{

}

searchAge(int studentID, int age)
{
    printf("Searching for student: %d, with age: %d.\n", studentID, age);

    printf("Student has been found.\n");
}

insertion(int studentID, int age)
{
    printf("Inserting student with ID: %d, and age: %d.\n", studentID, age);
    
    printf("Student has been added successfully.\n");
}

deletion(int age)
{
    printf("Removing students with age: %d.\n", age);

    printf("Student has been removed successfully.\n");
}

maxAgeGap()
{
    int ageGap;
    printf("The maximum age gap is %d years.\n", ageGap);
}