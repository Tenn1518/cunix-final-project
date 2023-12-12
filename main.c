#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "data.h"
#include "commands.h"

void register_teacher(char *teachers[], int *index);
char* login_as_teacher(char *teachers[], int index);
Student login_as_student(Student students[], int students_index);
void teacher_menu(Student students[], int* sindex, char *courses[], int* cindex);

int main(void)
{
    Student students[MAX];
    char *teachers[MAX];
    char *courses[MAX];
    int teachers_index = 0, students_index = 0, courses_index = 0;
    Student student;
    bool exit = false;

    /* Populate data from files on startup. */
    read_list_file(TEACHERS_FILE_NAME, teachers, &teachers_index);
    read_list_file(COURSES_FILE_NAME, courses, &courses_index);
    read_student_file(students, &students_index);

    srand(time(NULL));

    /* Main menu list of available options. */
    char *strs[] = {
	"Exit",
	"Register teacher account",
	"Student login",
	"Teacher login",
    };
    int choice;

    /* Main menu loop */
    while (!exit)
    {
	choice = select_item(strs, 4);
	char* logged_in = NULL;

	switch (choice)
	{
	case 0:
	    exit = true;
	    break;
	case 1:
	    register_teacher(teachers, &teachers_index);
	    break;
	case 2:
	    if (students_index == 0)
	    {
		printf("No students available. Please create a student first.\n\n");
	    }
	    else
	    {
		student = login_as_student(students, students_index);
		view_student_grades(student, courses, courses_index);
	    }
	    break;
	case 3:
	    /* TODO */
	    logged_in = login_as_teacher(teachers, teachers_index);
	    if (logged_in != NULL)
	    {
		teacher_menu(students, &students_index, courses, &courses_index);
	    }
	    break;
	}
    }

    printf("Saving data to %s, %s, and %s.\n", STUDENTS_FILE_NAME, TEACHERS_FILE_NAME, COURSES_FILE_NAME);
    write_teacher_file(teachers, teachers_index);
    write_student_file(students, students_index);
    write_courses_file(courses, courses_index);

    return 0;
}

/* New user registers their full name. */
void register_teacher(char *teachers[], int *index)
{
    char name[STR_LENGTH];

    printf("Enter full name of the teacher [Max length: %d]: ", STR_LENGTH);

    /* Use fgets so the user can input space-separated full name. */
    fgets(name, STR_LENGTH, stdin);

    /* Strip newline from the end of the inputted name. */
    strip_newline(name);

    teachers[*index] = strdup(name);

    /* Print confirmation of registration. */
    printf("New teacher %s with id %d\n"
           "Please write down the id %d to log in in the future.\n\n",
           teachers[*index], *index, *index);

    (*index)++;
}

/* User will input their teacher ID to log-in. */
char* login_as_teacher(char *teachers[], int index)
{
    unsigned int id = index;
    bool valid_id = false;
    char *logged_in;

    printf("\n");

    if (index == 0)
    {
	printf("Please register a teacher first.\n\n");
	return NULL;
    }

    while (!valid_id)
    {
	printf("Enter teacher user ID: ");
	scanf("%u", &id);

	if (id < index)
	{
	    valid_id = true;
	}
	else
	{
	    printf("Invalid id.\n");
	}
    }

    logged_in = teachers[id];
    printf("Welcome, %s.\n", logged_in);

    return logged_in;
}

Student login_as_student(Student students[], int students_index)
{
    int id = -1;
    Student *logged_in;
    bool valid_id = false;

    while (!valid_id)
    {
	printf("Enter student user ID: ");
	scanf("%d", &id);

	if (id >= 0 && id < students_index)
	{
	    valid_id = true;
	}
	else
	{
	    printf("Invalid student ID.\n");


	    while (getchar() != '\n');
	}
    }

    logged_in = &students[id];
    char *name = logged_in->full_name;
    printf("Welcome, %s.\n", name);

    return *logged_in;
}

/* Looping menu displaying operations available to teacher accounts. */
void teacher_menu(Student students[], int* sindex, char *courses[], int* cindex)
{
    bool exit = false;
    int choice;
    char *menu_items[] = {
        "Exit",
        "Add course",
        "View courses",
        "Create student",
        "Edit student grades",
        "View student grades",
        "Sort student grades",
        "Calculate grade average",
        "Search for student"
    };

    while(!exit)
    {
	choice = select_item(menu_items, 9);
	switch (choice)
	{
	case 0:
	    exit = true;
	    return;
	    break;
	case 1:
	    add_course(courses, MAX, cindex);
	    break;
	case 2:
	    view_courses(courses, MAX, *cindex);
	    break;
	case 3:
	    create_student(students, sindex);
	    break;
	case 4:
	    edit_student_grades(students, sindex, courses, cindex);
	    break;
	case 5:
	    teacher_view_student_grades(students, *sindex, courses, *cindex);
	    break;
	case 6:
	    sort_student_grades(students, *sindex, courses, *cindex);
        break;
    case 7:
        gradeAverage(students, *sindex, *cindex);
        break;
    case 8:
        studentSearch(students, *sindex);
        break;
	}
    }
}
