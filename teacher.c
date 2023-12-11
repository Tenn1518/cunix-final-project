/* Procedures for teachers to edit and add students and courses. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "teacher.h"
#include "data.h"

#define STR_LENGTH 80
#define MAX_COURSES 4

// Creates a new student and assigns courses with grades to student *UNFINISHED*
void create_student(Student students[], int* sindex)
{
    // Declare variables to grab names and grade from input
    char student_name[STR_LENGTH];
    char student_course[STR_LENGTH];
    unsigned int course_grade;

    printf("Enter the full name of the student: ");
    fgets(student_name, STR_LENGTH, stdin);

    strip_newline(student_name);

    Student new_student;
    new_student.full_name = strdup(student_name);

    // Add new student to array of students
    students[*sindex] = new_student;

    printf("New student %s, with id %d.\nStudent id must be given to the student.\n",student_name, sindex);
}

// Edit the grades for each course assigned to the student
// *SUBJECT TO CHANGE*
void edit_student_grades(Student students[], int* students_index)
{
    int student_id;
    printf("Enter the ID of the student to edit grades: ");
    scanf("%d", &student_id);

    if (student_id < 0 || student_id >= *students_index)
    {
        printf("Invalid student ID.\n");
    }

    Student *student = &students[student_id];

    // Edit grades for each course *SUBJECT TO CHANGE*
    for (int i = 0; i <= MAX_COURSES; i++)
    {
        // Check if the course exists
        if (student->courses[i].name != NULL)
        {
            printf("Enter new grade for %s: ", student->courses[i].name);
            scanf("%u", &student->courses[i].grade);
        }
    }

    printf("Grades for %s edited successfully.\n", student->full_name);
}

// Displays the grade and name for each course assigned to the student
void view_student_grades(Student students[], int* students_index)
{
    int student_id;
    printf("Enter the ID of the student to view grades: ");
    scanf("%d", &student_id);

    if (student_id < 0 || student_id >= *students_index)
    {
        printf("Invalid student ID.\n");
        return;
    }

    Student *student = &students[student_id];

    printf("Grades for %s:", student->full_name);


    for (int i = 0; i < MAX_COURSES; i++)
    {
        // Check if the course exists
        if (student->courses[i].name != NULL)
        {
            printf("%s: %u\n", student->courses[i].name, student->courses[i].grade);
        }
    }
}
