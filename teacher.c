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

    // Add new student to array of students
    students[*sindex] = new_student;
    printf("New student %s, with id %d.\nStudent id must be given to the student.\n", student_name, *sindex);

    *sindex++;
}

// Edit the grades for each course assigned to the student
// *SUBJECT TO CHANGE*
void edit_student_grades(Student students[], int* students_index)
{
/*     int student_id; */
/*     printf("Enter the ID of the student to edit grades: "); */
/*     scanf("%d", &student_id); */

/*     if (student_id < 0 || student_id >= *students_index) */
/*     { */
/*         printf("Invalid student ID.\n"); */
/*     } */

/*     Student *student = &students[student_id]; */

/*     // Edit grades for each course *SUBJECT TO CHANGE* */
/*     for (int i = 0; i <= MAX_COURSES; i++) */
/*     { */
/*         // Check if the course exists */
/*         if (student->courses[i].name != NULL) */
/*         { */
/*             printf("Enter new grade for %s: ", student->courses[i].name); */
/*             scanf("%u", &student->courses[i].grade); */
/*         } */
/*     } */

/*     printf("Grades for %s edited successfully.\n", student->full_name); */
}

// Displays the grade and name for each course assigned to the student
void view_student_grades(Student students[], int* students_index)
{
    /* int student_id; */
    /* printf("Enter the ID of the student to view grades: "); */
    /* scanf("%d", &student_id); */

    /* if (student_id < 0 || student_id >= *students_index) */
    /* { */
    /*     printf("Invalid student ID.\n"); */
    /*     return; */
    /* } */

    /* Student *student = &students[student_id]; */

    /* printf("Grades for %s:", student->full_name); */


    /* for (int i = 0; i < MAX_COURSES; i++) */
    /* { */
    /*     // Check if the course exists */
    /*     if (student->courses[i].name != NULL) */
    /*     { */
    /*         printf("%s: %u\n", student->courses[i].name, student->courses[i].grade); */
    /*     } */
    /* } */
}
