#include <stdio.h>
#include <string.h>

int select_item(char *choices[], int size);
void registerTeacher();
void loginTeacher();
void loginStudent();

int main(void)
{
    char *strs[] = {
        "Exit",
        "Register teacher account",
        "Teacher login",
	"Student login",
    };
    int choice;

    choice = select_item(strs, 3);

    /* printf("\nChoice made: %d: %s\n", choice, strs[choice]); */
    switch (choice)
    {
    case 0:
	printf("Exiting...\n");
	return 0;
    case 1:
	registerTeacher();
	break;
    case 2:
	loginStudent();
	break;
    case 3:
	loginTeacher();
	break;
    }

    return 0;
}

/* Creates menu from a list of possible choices the user can choose from as
 * strings.  Empty strings are skipped over, such as when you don't want a 0th
 * choice. */
int select_item(char *choices[], int size)
{
    int input = 0;

    for (int i = 0; i < size; i++)
    {
	char *str = choices[i];
	if (strcmp(str, "") != 0)
	    printf("%d) %s\n", i, choices[i]);
    }
    printf("\nEnter choice: ");
    scanf("%d", &input);

    return input;
}

void registerTeacher()
{
    
}
void loginTeacher()
{
    
}
void loginStudent()
{
    
}
