/*
 * File: college.h
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

# ifndef COLLEGE_H
# define COLLEGE_H

typedef struct set SET;

SET *createDataSet(int maxStudents);

void destroyDataSet(SET *sp);

void searchID(SET *sp, int studentID);

void insertion(SET *sp, int studentID, int age);

void deletion(SET *sp, int studentID);

# endif /* COLLEGE_H */