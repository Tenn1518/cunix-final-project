#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct teacher
{
    char *full_name;
} Teacher;

typedef struct course
{
    char* name;
    unsigned int grade;
} Course;

typedef struct student
{
    Course* courses;
    char* full_name;
} Student;

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
