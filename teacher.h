#ifndef TEACHER_H
#define TEACHER_H_

#include "data.h"

// Function declarations for teacher-related operations
void add_course(char *courses[], int size, int* index);
void view_courses(char *courses[], int size, int index);
void create_student(Student students[], int* index);
void edit_student_grades(Student students[], int* students_index, int* course_index);
void view_student_grades(Student students[], int* students_index, int* course_index);
void sort_student_grades(Student students[], int* students_index, int* course_index);
void gradeAverage(Student students[], int* students_index, int* course_index);


// Other declarations related to teachers if needed

#endif // TEACHER_H_

