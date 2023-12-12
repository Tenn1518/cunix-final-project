#ifndef DATA_H_
#define DATA_H_
#define MAX 25
#define STR_LENGTH 80
#define COURSE_STR_LENGTH 35
#define COURSES_FILE_NAME "courses.txt"
#define STUDENTS_FILE_NAME "students.txt"
#define TEACHERS_FILE_NAME "teachers.txt"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct student
{
    int course_grades[MAX];
    char full_name[STR_LENGTH];
} Student;

int select_item(char *choices[], int size);
void strip_newline(char *str);
void write_student_file(Student students[], int index);
void write_teacher_file(char *teachers[], int index);
void write_courses_file(char *courses[], int index);
void read_student_file(Student students[], int* index);
void read_list_file(char *filename, char *names[], int *index);

#endif // DATA_H_
