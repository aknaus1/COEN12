/*
 * In this project, you will implement an application to read words from a text file.  
 * The filename will be supplied onthe command line.  
 * Your program should display the total number of words in the file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_WORD_LENGTH 30

int main(int arg, char *argu[]){
    int counter = 0;
    char str[MAX_WORD_LENGTH];
    FILE *fp;
    if(arg!=2){
		printf("ERROR: NOT ENEOUGH ARGUMENTS");
		return 0;
	}
	fp = fopen(argu[1], "r");
	if(fp==NULL){
        printf("ERROR: UNABLE TO OPEN THE FILE");
        return 0;
    }
    while(fscanf(fp, "%s", str)==1){
        counter++;
    }
    printf("Word Count: %d\n", counter);
	fclose(fp);
    return 0;
}