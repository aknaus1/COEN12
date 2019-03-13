#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "dataset.c"

#define maxStudents 3000

int main(void)
{
    int i, studentID = 0, age;
    createDataSet(maxStudents);
    srand(time(NULL));
    for(i=0; i<1000; i++)
    {
        studentID += 1 + (rand()%2);
        age = 18 + (rand()%12);
        addStudent(studentID, age);
    }

}