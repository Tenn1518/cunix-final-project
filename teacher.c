/* Procedures for teachers to edit and add students and courses. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "teacher.h"
#include "data.h"

/* #define MAX_COURSES 4 */

void add_course(char *courses[], int size, int *index)
{
    char name[STR_LENGTH];

    if (size == *index)
    {
	printf("Maximum course limit of %d reached", MAX);
	return;
    }

    printf("Enter name of new course: ");
    fgets(name, STR_LENGTH, stdin);
    strip_newline(name);

    printf("Course no. %d (%s) added.\n", *index, name);

    courses[*index] = strdup(name);
    (*index)++;
}

void view_courses(char *courses[], int size, int index)
{
    printf("Courses offered:\n"
	   "----------------\n");
    for (int i = 0; i < index && i < size; i++)
    {
	printf("%d) %s\n", i + 1, courses[i]);
    }
    printf("\n\n");
}

// Creates a new student and assigns courses with grades to student *UNFINISHED*
void create_student(Student students[], int* sindex)
{
    // Declare variables to grab names and grade from input
    char student_name[STR_LENGTH];

    printf("Enter the full name of the student: ");
    fgets(student_name, STR_LENGTH, stdin);

    strip_newline(student_name);

    Student new_student;
    strcpy(new_student.full_name, student_name);

    // Initialize course grades for the new student
    for (int i = 0; i < MAX_COURSES; i++)
    {
        new_student.course_grades[i] = 0;
    }

    // Add new student to array of students
    students[*sindex] = new_student;
    printf("New student %s, with id %d.\nStudent id must be given to the student.\n", student_name, *sindex);

    (*sindex)++;
}



// Edit the grades for each course assigned to the student
// *SUBJECT TO CHANGE*
void edit_student_grades(Student students[], int* sindex, int* cindex)
{
    int student_id;
    printf("Enter the ID of the student to edit grades: ");
    scanf("%d", &student_id);

    if (student_id < 0 || student_id >= *sindex)
    {
        printf("Invalid student ID.\n");
        return;
    }

    Student *student = &students[student_id];


    for (int i = 0; i < *cindex; i++)
    {
        printf("Enter new grade for Course %d: ", i + 1);
        scanf("%d", &student->course_grades[i]);
    }

    printf("Grades for %s edited successfully.\n", student->full_name);
}

// Displays the grade and name for each course assigned to the student
void view_student_grades(Student students[], int* sindex, int* cindex)
{
    int student_id;
    printf("Enter the ID of the student to view grades: ");
    scanf("%d", &student_id);

    if (student_id < 0 || student_id >= *sindex)
    {
        printf("Invalid student ID.\n");
        return;
    }

    Student *student = &students[student_id];

    printf("Grades for %s:\n", student->full_name);

    for (int i = 0; i < *cindex; i++)
    {
        printf("%d, ",student->course_grades[i]);
    }
}
// Sorts student grades from highest to lowest grade value.
void sort_student_grades(Student students[], int* sindex, int* cindex)
{
    int student_id;
    printf("Enter the ID of the student to sort grades: ");
    scanf("%d", &student_id);

    if (student_id >= *sindex)
    {
        printf("Invalid student ID.\n");
        return;
    }

    Student *student = &students[student_id];

    // Bubble Sort algorithm, sorts from highest to lowest
    for (int i = 0; i < *cindex - 1; i++)
    {
        for (int j = 0; j < *cindex - i - 1; j++)
        {
            if (student->course_grades[j] < student->course_grades[j + 1])
            {
                int temp = student->course_grades[j];
                student->course_grades[j] = student->course_grades[j + 1];
                student->course_grades[j + 1] = temp;
            }
        }
    }

    printf("Grades for %s sorted from highest to lowest.\n", student->full_name);
}

//**UNFINISHED**//
//Calculated the average of the students grades
void gradeAverage(Student students[], int* sindex, int* cindex)
{
    int student_id;
    double accum = 0;
    printf("Enter the ID of the student to sort grades: ");
    scanf("%d", &student_id);

    if (student_id >= *sindex)
    {
        printf("Invalid student ID.\n");
        return;
    }

    Student *student = &students[student_id];


    for(int i = 0; i < *cindex; i++)
    {
        accum += student->course_grades[i];

    }

    printf("Average of student grades: %.2lf",(accum/(*cindex)));
}
