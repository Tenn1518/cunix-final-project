#define MAX 25
#define STR_LENGTH 80

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "data.h"
#include "teacher.h"

void register_teacher(Teacher list[], int index);
Teacher* login_as_teacher(Teacher list[], int index);
void login_as_student(Student students[], int students_index);
void teacher_menu(Teacher* teacher, Student students[], int *sindex);

int main(void)
{
    Student students[MAX];
    Teacher teachers[MAX];
    char *courses[MAX];
    int teachers_index = 0, students_index = 0;
    bool exit = false;

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
	Teacher* logged_in;

	switch (choice)
	{
	case 0:
	    exit = true;
	    return 0;
	case 1:
	    register_teacher(teachers, teachers_index);
	    teachers_index++;
	    break;
	case 2:
	    /* TODO */
	    login_as_student(students, students_index);
	    break;
	case 3:
	    /* TODO */
	    logged_in = login_as_teacher(teachers, teachers_index);
	    if (logged_in != NULL)
	    {
		teacher_menu(logged_in, students, &students_index);
	    }
	    break;
	}
    }
    return 0;
}

/* New user registers their full name. */
void register_teacher(Teacher list[], int index)
{
    char name[STR_LENGTH];
    Teacher new_t;

    printf("Enter full name of the teacher [Max length: %d]: ", MAX);

    /* Use fgets so the user can input space-separated full name. */
    fgets(name, STR_LENGTH, stdin);

    /* Strip newline from the end of the inputted name. */
    for (int i = 0; i < STR_LENGTH; i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
        }
    }

    //Dynamically allocate memory space for the teacher name.
    new_t.full_name = malloc(strlen(name) + 1);
    strcpy(new_t.full_name, name);

    /* Print confirmation of registration. */
    printf("New teacher %s with id %d\n"
           "Please write down the id %d to log in in the future.\n\n",
           new_t.full_name, index, index);

    list[index] = new_t;
}

/* User will choose their teacher id. TODO */
Teacher* login_as_teacher(Teacher list[], int index)
{
    unsigned int id = index;
    Teacher *logged_in;
    bool valid_id = false;

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

    logged_in = &list[id];
    char* name = logged_in->full_name;
    printf("Welcome, %s.\n", name);

    return logged_in;
    /* teacher_menu(list, students, sindex); */
}

void login_as_student(Student students[], int students_index)
{
    int id = -1;
    Student *logged_in;
    bool valid_id = true;

    if (students_index == 0)
    {
        printf("No students available. Please create a student first.\n\n");
        return;
    }

    while (!valid_id)
    {
        printf("Enter student user ID: ");
        scanf("%d", &id);

        if (id < 0 || id >= students_index)
        {
            printf("Invalid student ID.\n");
        }
        else
        {
            valid_id = true;
        }
    }

    logged_in = &students[id];
    char *name = logged_in->full_name;
    printf("Welcome, %s.\n", name);

}

/* TODO: UNFINISHED */
void teacher_menu(Teacher* teacher, Student students[], int* sindex)
{
    bool exit = false;
    int choice;
    char *menu_items[] = {
        "Exit",
        "Add course",
        "View courses",
        "Create student",
        "Edit student grades",
        "View student grades"
    };

    while(!exit)
    {
	choice = select_item(menu_items, 6);
	switch (choice)
	{
	case 0:
	    exit = true;
	    return;
	    break;
	case 1:
	    /* TODO - Add courses */
	    break;
	case 2:
	    /* TODO - View courses  */
	    break;
	case 3:
	    create_student(students, sindex);
	    sindex++;
	    break;
	case 4:
	    edit_student_grades(students, sindex);
	    break;
	case 5:
	    view_student_grades(students, sindex);
	}
    }
}
