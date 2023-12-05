#include <string.h>
#include <stdlib.h>

typedef struct teacher
{
    char *full_name;
} Teacher;

typedef struct course
{
    char* name;
    unsigned int grade;
} Course;

typedef struct student
{
    Course* courses;
    char* full_name;
} Student;
