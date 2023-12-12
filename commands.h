#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "data.h"

// Function declarations for teacher-related operations
void add_course(char *courses[], int size, int* index);
void view_courses(char *courses[], int size, int index);
void create_student(Student students[], int* index);
void edit_student_grades(Student students[], int* students_index, char *courses[], int* course_index);
void view_student_grades(Student students[], int student_id, char *courses[], int cindex);
void teacher_view_student_grades(Student students[], int students_index, char *courses[], int course_index);
void sort_student_grades(Student students[], int sindex, char *courses[], int cindex);
void gradeAverage(Student students[], int students_index, int course_index);
int select_student(Student students[], int sindex);

// Other declarations related to teachers if needed

#endif // COMMANDS_H_

