#include "data.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Creates menu from a list of possible choices the user can choose from as
 * strings.  Empty strings are skipped over, such as when you don't want a 0th
 * choice.  User's input is validated. */
int select_item(char *menu_items[], int size)
{
    int input = -1;

    printf("\n");

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

/* Return ID of student selected by teacher. */
int select_student(Student students[], int sindex)
{
    unsigned int id;
    Student *student = NULL;

    for (int i = 0; i < sindex; i++)
    {
	char *name = students[i].full_name;
	printf("%d) %s\n", i, name);
    }

    printf("\nEnter the ID of the student: ");
    do
    {
	scanf("%d", &id);
	
	if (id > sindex)
	{
	    printf("Invalid student ID.\n"
		   "Enter the ID of the student:");
	}
    } while (id > sindex);
    
    return id;
}

void strip_newline(char *str)
{
    // Remove new line character from student name
    // replace with terminating char
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
	str[len - 1] = '\0';
    }
}
