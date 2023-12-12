/* Procedures for teachers to edit and add students and courses. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "commands.h"
#include "data.h"

/* Adds a name for subsequent courses */
void add_course(char *courses[], int size, int *index)
{
    char name[COURSE_STR_LENGTH];

    if (size == *index)
    {
	printf("Maximum course limit of %d reached", MAX);
	return;
    }

    printf("Enter name of new course: ");
    fgets(name, COURSE_STR_LENGTH, stdin);
    strip_newline(name);

    printf("Course no. %d (%s) added.\n", *index + 1, name);

    courses[*index] = strdup(name);
    (*index)++;
}

void view_courses(char *courses[], int size, int index)
{
    if (index == 0)
    {
	printf("Error: Add courses first!\n");
	return;
    }

    printf("Courses offered:\n"
	   "----------------\n");
    for (int i = 0; i < index && i < size; i++)
    {
	printf("%d) %s\n", i + 1, courses[i]);
    }
}

// Creates a new student and assigns courses with grades to student
void create_student(Student students[], int* sindex)
{
    // Declare variables to grab names and grade from input
    char student_name[STR_LENGTH];
    Student new_student;

    /* Size validation. */
    if (*sindex >= MAX)
    {
	printf("Error: Reached limit of maximum number of students (%d).\n", MAX);
	return;
    }

    printf("Enter the full name of the student: ");
    fgets(student_name, STR_LENGTH, stdin);

    strip_newline(student_name);

    strcpy(new_student.full_name, student_name);

    // Initialize course grades as unenrolled for the new student
    for (int i = 0; i < MAX; i++)
    {
        new_student.course_grades[i] = -1;
    }

    // Add new student to array of students
    students[*sindex] = new_student;
    printf("New student %s, with id %d.\nStudent id must be given to the student.\n", student_name, *sindex);

    (*sindex)++;
}

// Edit the grades for each course assigned to the student
void edit_student_grades(Student students[], int* sindex, char *courses[], int* cindex)
{
    int student_id;
    Student *student;

    /* Validate students and courses exist first. */
    if (*sindex == 0 || cindex == 0)
    {
        printf("Error: Are you sure you've added courses and students yet?\n");
	return;
    }

    student_id = select_student(students, *sindex);
    student = &students[student_id];

    for (int i = 0; i < *cindex; i++)
    {
	char *course_name = courses[i];
	int new_grade;

	/* Only valid inputs are between [-1, 100]. */
	printf("Acceptable values for course grade input:\n"
	       "-1: Student unenrolled in course\n"
	       "0-100: Current grade of student\n");
	do
	{
	    printf("Enter new grade for Course %d (%s), or -1 to unenroll: ", i + 1, course_name);
	    scanf("%d", &new_grade);
	} while (new_grade < -1 || new_grade > 100);
	student->course_grades[i] = new_grade;
    }

    printf("Grades for %s edited successfully.\n", student->full_name);
}

/* Displays the grade and name for each course assigned to the student.
 * Parameters are copied by value as viewing is non-destructive. */
void teacher_view_student_grades(Student students[], int sindex, char *courses[], int cindex)
{
    int student_id;
    Student student;

    /* Validate courses and students exist first. */
    if (sindex == 0 || cindex == 0)
    {
	printf("Error: Are you sure you've added courses and students yet?\n");
	return;
    }

    student_id = select_student(students, sindex);
    student = students[student_id];

    view_student_grades(student, courses, cindex);
}

/* Print out grades of student based on ID.  ID is expected to be within bounds
 * of students array. */
void view_student_grades(Student student, char *courses[], int cindex)
{
    printf("Grades for %s:\n"
           "------------------------------------+----\n", student.full_name);

    for (int i = 0; i < cindex; i++)
    {
        int grade = student.course_grades[i];
        if (grade != -1)
        {
	    printf("%-35s | %3d\n", courses[i], grade);
        }
    }
}

// Sorts student grades from highest to lowest grade value.
void sort_student_grades(Student students[], int sindex, char *courses[], int cindex)
{
    int student_id;
    struct grade
    {
        char *name;
	int grade;
    };
    struct grade grades[cindex];

    /* Size validation */
    if (sindex == 0 || cindex == 0)
    {
	printf("Error: Are you sure you've added courses and students yet?\n");
	return;
    }

    /* Get pointer to student selected by user. */
    student_id = select_student(students, sindex);
    Student student = students[student_id];

    /* Group course name and student's grade for sorting and displaying */
    for (int i = 0; i < cindex; i++)
    {
	struct grade grade = {courses[i], student.course_grades[i]};
	grades[i] = grade;
    }

    // Bubble Sort algorithm, sorts from highest to lowest
    for (int i = 0; i < cindex - 1; i++)
    {
	for (int j = 0; j < cindex - i - 1; j++)
	{
	    if (grades[j].grade < grades[j + 1].grade)
	    {
    // Swap grades when higher value grade is encountered
		struct grade temp = grades[j];
		grades[j] = grades[j + 1];
		grades[j + 1] = temp;
	    }
	}
    }

    // Print out new sorted list from high to low
    printf("\nGrades for %s sorted from highest to lowest:\n\n", student.full_name);
    for (int i = 0; i < cindex; i++)
    {
	struct grade course = grades[i];
	// Print grades for enrolled courses
	if (course.grade != -1)
	{
	    printf("%-35s | %3d\n", course.name, course.grade);
	}
    }
}

// Calculated the average of the students grades
void gradeAverage(Student students[], int sindex, int cindex)
{
    int student_id;
    double accum = 0;
    int courseCount = 0;
    Student *student;

    /* Get id from user */
    student_id = select_student(students, sindex);
    student = &students[student_id];

    /* Sum the grades and divide by number of courses. */
    for (int i = 0; i < cindex; i++)
    {
        // Calculate average for enrolled courses only
        if(student->course_grades[i] > 0)
        {
            //Increment counter for enrolled courses
            courseCount++;

            // accumulate all grades
            accum += student->course_grades[i];
        }
    }

    printf("Average of student grades: %.2lf",(accum/(courseCount)));
}

/* String matches a name in students */
void studentSearch(Student students[], int sindex)
{
    char name[STR_LENGTH];
    bool found = false;

    printf("Enter the name of the student you wish to search for(Case sensitive): ");

    fgets(name, STR_LENGTH, stdin);

    strip_newline(name);

    for(int i = 0; i < sindex; i++)
    {
        // Compare input string to student name
        if(strcmp(name,students[i].full_name) == 0)
        {
            printf("Student, %s, found with ID: %d.\n", name,i);
            found = true;
            break;
        }

    }

    if(!found)
    {
	printf("Student, %s, was not found.\n", name);
    }

}
