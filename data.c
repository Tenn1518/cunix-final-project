#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *full_name;
} Teacher;

typedef struct
{
    char* name;
    unsigned int grade;
} Course;

typedef struct
{
    Course* courses;
    char* full_name;
} Student;
