#define MAX 25
#define STR_LENGTH 80

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "data.h"
#include "teacher.h"

int select_item(char *choices[], int size);
void register_teacher(Teacher list[], int index);
void login_as_teacher(Teacher list[], int index);
void login_as_student();

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
	    login_as_student();
	    break;
	case 3:
	    /* TODO */
	    login_as_teacher(teachers, teachers_index);
	    break;
	}
    }
    return 0;
}

/* Creates menu from a list of possible choices the user can choose from as
 * strings.  Empty strings are skipped over, such as when you don't want a 0th
 * choice.  User's input is validated. */
int select_item(char *menu_items[], int size)
{
    int input = -1;

    /* Print each menu item */
    for (int i = 0; i < size; i++)
    {
	char *item = menu_items[i];
	if (strcmp(item, "") != 0)
	    printf("%d) %s\n", i, menu_items[i]);
    }

    /* User chooses from items.  Validate user input */
    while (input > size || input < 0)
    {
	char c;
	printf("\nEnter choice: ");
	scanf("%d", &input);
	/* scanf leaves a newline in stdin, so remove it to avoid messing up
	 * future input/fgets calls. */
	while((c = getchar()) != '\n' && c != EOF);
    }

    return input;
}

/* New user registeres their full name. */
void register_teacher(Teacher list[], int index)
{
    char name[STR_LENGTH];
    Teacher new_t;

    printf("Enter full name of the teacher [Max length: %d]: ", MAX);

    /* Use fgets so user can input space-separated full name. */
    fgets(name, STR_LENGTH, stdin);

    /* Strip newline from end of inputted name. */
    for (int i = 0; i < STR_LENGTH; i++)
    {
	if (name[i] == '\n')
	{
	    name[i] = '\0';
	}
    }

    /* Print confirmation of registration. */
    printf("New teacher %s with id %d\n"
           "Please write down the id %d to login in the future.\n\n",
           name, index, index);

    new_t.full_name = name;
    
    list[index] = new_t;
}

/* User will choose their teacher id. TODO */
void login_as_teacher(Teacher list[], int index)
{
    unsigned int id = index;
    Teacher *logged_in;
    bool valid_id = false;

    if (index == 0)
    {
	printf("Please register a teacher first.\n\n");
	return;
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
}

/* TODO: UNFINISHED */
void teacher_menu(Teacher teacher)
{
    int choice;
    char *menu_items[] = {
        "Exit",
	"Add course",
        "View courses",
        "Create student",
        "Edit student grades",
        "View student grades"
    };

    choice = select_item(menu_items, 5);

    switch (choice)
    {
    case 0:
	return;
	break;
    case 1:
	/* TODO */
    }
}

void login_as_student()
{
    
}
