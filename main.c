#define MAX 25
#define STR_LENGTH 80

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "data.c"

int select_item(char *choices[], int size);
void registerTeacher(Teacher list[], int index);
void loginTeacher();
void loginStudent();

int main(void)
{
    Student students[MAX];
    Teacher teachers[MAX];
    int teachers_index = 0, students_index = 0;
    bool exit = false;

    srand(time(NULL));
    
    /* Main menu list of available options. */
    char *strs[] = {
	"Exit",
	"Register teacher account",
	"Teacher login",
	"Student login",
    };
    int choice;

    /* Main menu loop */
    while (!exit)
    {
	choice = select_item(strs, 3);

	/* printf("\nChoice made: %d: %s\n", choice, strs[choice]); */
	switch (choice)
	{
	case 0:
	    exit = true;
	    return 0;
	case 1:
	    registerTeacher(teachers, teachers_index);
	    teachers_index++;
	    break;
	case 2:
	    /* TODO */
	    loginStudent();
	    break;
	case 3:
	    /* TODO */
	    loginTeacher();
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

void registerTeacher(Teacher list[], int index)
{
    char name[STR_LENGTH];
    Teacher new_t;

    printf("What is the full name of the teacher? ");

    /* Use fgets so user can input space-separated full name. */
    fgets(name, STR_LENGTH, stdin);
    /* Strip newline from end of inputted name. */
    /* sscanf(name, "%s\n", name); */

    printf("New teacher %s with id %d\n"
           "Please write down the id %d to login in the future.\n\n",
           name, index, index);
         
    list[index] = new_t;
}

/* User will choose their teacher id. */
void loginTeacher()
{
    
}
void loginStudent()
{
    
}
