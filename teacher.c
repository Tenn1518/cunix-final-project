/* Procedures for teachers to edit and add students and courses. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "teacher.h"
#include "data.h"

#define STR_LENGTH 80
#define MAX_COURSES 5

// Creates a new student and assigns courses with grades to student *UNFINISHED*
void create_student(Student students[], int index)
{
    // Declare variables to grab names and grade from input
    char student_name[STR_LENGTH];
    char student_course[STR_LENGTH];
    unsigned int course_grade;

    printf("Enter the full name of the student: ");
    fgets(student_name, STR_LENGTH, stdin);

    Student new_student;
    new_student.full_name = strdup(student_name);

    for(int i = 0; i < MAX_COURSES; i++)
    {
        printf("Enter course name: ");
        fgets(student_course, STR_LENGTH, stdin);


        new_student.courses[i].name = strdup(student_course);

        printf("Enter course grade: ");
        scanf(" %u", &course_grade);    // Space before identifier to consume the newline character
        new_student.courses[i].grade = course_grade;


    }


    // Add new student to array of students
    students[index] = new_student;

    printf("New student, %s with id %d\n"
           "Student id must be given to the student.\n\n",
           student_name, index);
}

void edit_student_grades(Student students[], int students_index)
{
    // TODO
}

void view_student_grades(Student students[], int students_index)
{
   // TODO
}
