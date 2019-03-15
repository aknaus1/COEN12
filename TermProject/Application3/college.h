/*
 * File:        college.h
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

# ifndef COLLEGE_H
# define COLLEGE_H

typedef struct node NODE;
typedef struct set SET;

SET *createDataSet();

void destroyDataSet(SET *sp);

void searchAge(SET *sp, int age);

void *searchID(SET *sp, int studentID);

void insertion(SET *sp, int studentID, int age);

void deletion(SET *sp, int studentID);

void maxAgeGap(SET *sp);

# endif /* COLLEGE_H */