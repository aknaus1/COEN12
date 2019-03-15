/*
 * File:        college.h
 * 
 */

# ifndef COLLEGE_H
# define COLLEGE_H

typedef struct set SET;

SET *createDataSet(int maxStudents);

void destroyDataSet(SET *sp);

void searchID(SET *sp, int studentID);

void insertion(SET *sp, int studentID, int age);

void deletion(SET *sp, int studentID);

# endif /* COLLEGE_H */