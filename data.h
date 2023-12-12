#ifndef DATA_H_
#define DATA_H_
#define MAX_COURSES 8
#define MAX 25
#define STR_LENGTH 80
#define COURSE_STR_LENGTH 35

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int select_item(char *choices[], int size);
void strip_newline(char *str);

typedef struct teacher
{
    char full_name[STR_LENGTH];
} Teacher;

/* typedef struct course */
/* { */
/*     char* name; */
/*     unsigned int grade; */
/* } Course; */

typedef struct student
{
    int course_grades[MAX_COURSES];
    char full_name[STR_LENGTH];
} Student;

#endif // DATA_H_
