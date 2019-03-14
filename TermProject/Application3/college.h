/*
 * File:        college.h
 * 
 */

# ifndef COLLEGE_H
# define COLLEGE_H

typedef struct node NODE;
typedef struct set SET;

SET *createDataSet();

void destroyDataSet(SET *sp);

void searchAge(SET *sp, int age);

static void *searchID(SET *sp, int studentID);

void insertion(SET *sp, int studentID, int age);

void deletion(SET *sp, int studentID);

void maxAgeGap(SET *sp);

# endif /* COLLEGE_H */